/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:28 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:29 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	    is_power_of_2(unsigned int n)
{
	return (n > 0 && (n & (n-1)) == 0);
}

#include <stdio.h>

int main()
{
	printf("%d", is_power_of_2(0));
	return (0);
}
// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

// int	    is_power_of_2(unsigned int n);