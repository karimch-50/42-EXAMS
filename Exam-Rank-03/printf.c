/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:00:03 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/23 08:21:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	else
		count += ft_putchar(nbr + '0');
	return (count);
}

int	ft_puthex(unsigned int nbr)
{
	int	count;
	char	hex[] = "0123456789abcdef";

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16);
		count += ft_puthex(nbr % 16);
	}
	else
		count += ft_putchar(hex[nbr]);
	return (count);
}

int	check_args(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(list, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(list, long));
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check_args(list, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}

// int main()
// {
// 	// ft_printf("Magic %s is %d", "number", 42);
// 	// ft_printf("%x\n", -2147483648);
// 	ft_printf("%x\n", -2147483648);
// 	printf("%x\n", -2147483648);
// 	// printf("%x\n", INT_MAX + 1);
// 	// printf("%d", printf("%d\n", 1234));
// 	// printf("----------------");
// 	// printf("%s\n", "test");
// 	return (0);
// }



// Assignment name  : ft_printf
// Expected files   : ft_printf.c
// Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
// --------------------------------------------------------------------------------

// Write a function named `ft_printf` that will mimic the real printf but
// it will manage only the following conversions: s,d and x.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
// To test your program compare your results with the true printf.

// Exemples of the function output:

// call: ft_printf("%s\n", "toto");
// out: toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out: Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out: Hexadecimal for 42 is 2a$

// Obs: Your function must not have memory leaks. Moulinette will test that.