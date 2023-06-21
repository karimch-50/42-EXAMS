/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:15:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/23 08:21:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	has_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*join(char *s1, char *s2)
{
	char	*output;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	output = malloc(len(s1) + len(s2) + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		output[i++] = *s1++;
	while (s2 && *s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}

char	*save_stash(char *save, int fd)
{
	char	*buffer;
	char	*tmp;
	int		x;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1337)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buffer[x] = '\0';
		tmp = save;
		save = join(save, buffer);
		free(tmp);
		if (has_newline(buffer))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_line(char *str)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	output = malloc(i + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		output[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*save_rest(char	*str)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	output = malloc(len(str) - i);
	if (!output)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		output[j++] = str[i++];
	output[j] = '\0';
	free(str);
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = save_stash(save, fd);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = save_rest(save);
	return (line);
}


// int main()
// {
// 	int fd = open("test", O_RDONLY);
// 	// get_next_line(fd);
// 	char	*line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	while (1);
// 	return (0);
// }

// Assignment name : get_next_line
// Expected files : get_next_line.c (42_EXAM can't take .h for now)
// Allowed functions: read, free, malloc
// --------------------------------------------------------------------------------

// Write a function named get_next_line which prototype should be:
// char *get_next_line(int fd);


// Your function must return a line that has been read from the file descriptor passed as parameter. 
// What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

// The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, 
// you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

// In case of error return NULL. In case of not returning NULL, the pointer should be free-able.
// Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

// Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc,
// except the line that has been returned.

// Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file 
// descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

// Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

// No call to another function will be done on the file descriptor between 2 calls of get_next_line().
// Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.