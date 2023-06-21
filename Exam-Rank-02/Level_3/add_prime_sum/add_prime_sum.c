/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:35:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_prim(int nbr)
{
	int	i;

	if (nbr == 2)
		return (1);
	else if (nbr <= 1)
		return (0);
	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	output;
	int	i;

	i = 0;
	output = 0;
	while (str[i] && str[i] >= '0'  && str[i] <= '9')
		output = output * 10 + str[i++] - '0';
	return (output);
}

void	ft_putnbr(int nbr)
{
	char res;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		res = nbr + '0';
		write(1, &res, 1);
	}
}

int	main(int argc, char **argv)
{
	int	num;
	int	sum;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		sum = 0;
		while (num)
		{
			if (is_prim(num))
				sum += num;
			num--;
		}
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>