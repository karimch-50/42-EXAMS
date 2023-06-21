/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:36:16 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:36:17 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

int main(int argc, char **argv)
{
	int f;
	int	l;
	int nbr;

	if (argc == 3)
	{
		f = atoi(argv[1]);
		l = atoi(argv[2]);
		nbr = f > l ? f : l;
		if (f == 0 || l == 0)
		{
			ft_putnbr(0);
			write(1, "\n", 1);
			return (0);
		}
		while (1)
		{
			if (f % nbr == 0 && l % nbr == 0)
				break;
			nbr--;
		}
	}
	write(1, "\n", 1);
}

// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $