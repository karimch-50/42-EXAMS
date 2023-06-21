/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:35:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	wd_match(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i] != s2[j])
			j++;
		if (s1[i] == s2[j])
		{
			j++;
			i++;
		}
		else
			break ;
	}
	if (s1[i] == '\0')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (wd_match(argv[1], argv[2]))
			while(argv[1][i])
				write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $