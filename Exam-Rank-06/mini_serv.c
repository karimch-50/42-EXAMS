#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

typedef struct client {
	int id;
	char *msg;
}	t_client;

t_client clients[1024];

fd_set fds, read_fd;

char bufRead[1024], bufWrite[50];

int max_fd = 0, next_id = 0;

void printError(char *msg) {
	write (2, msg, strlen(msg));
	exit(1);
}

void	broadCast(int client, char *msg) {
	for (int fd = 0; fd <= max_fd; fd++)
		if (FD_ISSET(fd, &fds) && fd != client)
			send(fd, msg, strlen(msg), 0);
}

int extract_message(char **buf, char **msg) {
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				printError("Fatal error\n");
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

void	send_all(int fd) {
	char *msg = NULL;

	while (extract_message(&(clients[fd].msg), &msg)) {
		sprintf(bufWrite, "client %d: ", clients[fd].id);
		broadCast(fd, bufWrite);
		broadCast(fd, msg);
		free (msg);
	}
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int main(int ac, char **av) {
	if (ac != 2)
		printError("Wrong number of arguments\n");

	struct sockaddr_in servaddr, cli; 

	int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		printError("Fatal error\n");

	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));
  
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
		printError("Fatal error\n");

	if (listen(sockfd, 10) != 0) 
		printError("Fatal error\n");

	socklen_t len = sizeof(cli);
	FD_ZERO(&fds);
	FD_SET(sockfd, &fds);
	max_fd = sockfd;
	while (1) {
		read_fd = fds;
		int ret = select (max_fd + 1, &read_fd, NULL, NULL, NULL);
		if (ret == 0)
			continue ;
		if (ret < 0)
			printError("Fatal error\n");

		for (int fd = 0; fd <= max_fd; fd++) {
			if (!FD_ISSET(fd, &read_fd))
				continue;
			
			if (fd == sockfd) {
				int client_fd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (client_fd <= 0)
					continue ;

				max_fd = (client_fd > max_fd) ? client_fd : max_fd;
				clients[client_fd].id = next_id++;
				clients[client_fd].msg = NULL;
				sprintf(bufWrite, "server: client %d just arrived\n", clients[client_fd].id);
				broadCast(client_fd, bufWrite);
				FD_SET(client_fd, &fds);
				break ;
			}
			else {
				int res = recv(fd, bufRead, 1024, 0);
				if (res <= 0) {
					sprintf(bufWrite, "server: client %d just left\n", clients[fd].id);
					broadCast(fd, bufWrite);
					FD_CLR(fd, &fds);
					close(fd);
					free (clients[fd].msg);
					break ;
				}
				else {
					bufRead[res] = 0;
					clients[fd].msg = str_join(clients[fd].msg, bufRead);
					send_all(fd);
				}
			}
		}
	}
}
