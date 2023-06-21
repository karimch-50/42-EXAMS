/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	arr[128];
	int		i;
	int		j;

	j = 1;
	if (argc == 3)
	{
		while (j < 3)
		{
			i = 0;
			while (argv[j][i])
				arr[(int)argv[j][i++]] = 1;
			j++;
		}
		j = 1;
		while (j < 3)
		{
			i = 0;
			while (argv[j][i])
			{
				if (arr[(int)argv[j][i]] == 1)
				{
					write(1, &argv[j][i], 1);
					arr[(int)argv[j][i]] = 2;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
}

// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$

// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>