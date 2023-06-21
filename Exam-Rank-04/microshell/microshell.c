/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:35:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/06/21 13:35:13 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Assignment name  : microshell
// Expected files   : microshell.c
// Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
// --------------------------------------------------------------------------------------

// Write a program that will behave like executing a shell command
// - The command line to execute will be the arguments of this program
// - Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)
// - You must implement "|" and ";" like in bash
// 	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"
// - Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
// 	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
// 	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
// 	- a cd command will never be immediately followed or preceded by a "|"
// - You don't need to manage any type of wildcards (*, ~ etc...)
// - You don't need to manage environment variables ($BLA ...)
// - If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit
// - If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)
// - Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

// for example this should work:
// $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
// microshell
// i love my microshell
// $>

// Hints:
// Don't forget to pass the environment variable to execve

// Hints:
// Do not leak file descriptors!