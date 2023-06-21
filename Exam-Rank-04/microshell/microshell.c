#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_putstr(char *str, char *arg)
{
	while (str && *str)
		write(2, str++, 1);
	while (arg && *arg)
		write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	cd_command(char **av, int i)
{
	if (i != 2)
		return (ft_putstr("error: cd: bad arguments", NULL));
	if (chdir(av[1]) == -1)
		return (ft_putstr("error: cd: cannot change directory to ", av[1]));
	return (0);
}

int	exec_command(char **av, char **envp, int i)
{
	int pid;
	int	tub[2];
	int status;
	int is_pipe;

	is_pipe = 0;
	status = 0;
	if (av[i] && !strcmp(av[i], "|"))
	{
		is_pipe = 1;
		if (pipe(tub) == -1)
			return (ft_putstr("error: fatal", NULL));
	}
	pid = fork();
	if (pid == -1)
		return (ft_putstr("error: fatal", NULL));
	if (pid == 0)
	{
		av[i] = NULL;
		if (is_pipe && (dup2(tub[1], 1) == -1 || close(tub[0]) == -1 || close (tub[1]) == -1))
			return (ft_putstr("error: fatal", NULL));
		if (execve(av[0], av, envp))
			return (ft_putstr("error: cannot execute ", av[0]));
	}
	if (is_pipe)
	{
		if (dup2(tub[0], 0) == -1 || close(tub[0]) == -1 || close (tub[1]) == -1)
			return (ft_putstr("error: fatal", NULL));
	}
	waitpid(pid, &status, 0);
	return (status >> 8);
}

int main(int ac, char **av, char **env)
{
	int status;
	int i;

	i = 0;
	status = 0;
	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if (*av && !strcmp(*av, "cd"))
				status = cd_command(av, i);
			else if (i)
				status = exec_command(av, env, i);
		}
	}
	return (status);
}
