/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:35:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:59:16 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	is_valid(char c, int len)
{
	int i = 0;
	char str[] = "0123456789abcdef";
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	output;
	int	sign;
	int	n;
	int	i;

	output = 0;
	sign = 1;
	n = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_valid(ft_tolower(str[i]), str_base))
	{
		n = ft_tolower(str[i]);
		if (str[i] >= '0' && str[i] <= '9')
			n -= '0';
		else if (ft_tolower(str[i]) >= 'a' && ft_tolower(str[i]) <= 'f')
			n -= 'a' - 10;
		output = output * str_base + n;
		i++;
	}
	return (output * sign);
}
#include <stdlib.h>

int	main(int ac, char **av)
{
	printf("%d", ft_atoi_base(av[1], atoi(av[2])));
	return (0);
}
// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);
