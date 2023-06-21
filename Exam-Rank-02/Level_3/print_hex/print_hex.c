/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:36:20 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:36:21 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	hex_to_decimal(int nbr)
{
	if (nbr > 16)
	{
		hex_to_decimal(nbr / 16);
		hex_to_decimal(nbr % 16);
	}
	else
		write(1, &"0123456789abcdef"[nbr], 1);
}

int	mini_atoi(char *str)
{
	int output;
	int i;

	output = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		output = output * 10 + str[i++] - '0';
	return (output);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		hex_to_decimal(mini_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}



// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $
