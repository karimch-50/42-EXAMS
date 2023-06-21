/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:32:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:32:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	// write(1, str, sizeof(str));
	while (*str)
		write(1, str++, 1);
}

int main()
{
	ft_putstr("test");
	return (0);
}

// Assignment name  : ft_putstr
// Expected files   : ft_putstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that displays a string on the standard output.

// The pointer passed to the function contains the address of the string's first
// character.

// Your function must be declared as follows:

// void	ft_putstr(char *str);