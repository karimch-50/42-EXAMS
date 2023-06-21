/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:32 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:33 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	int	end;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i--;
		while (i != 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i--;
		end = i;
		while (i != 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		i++;
		while (i <= end)
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>