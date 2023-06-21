/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:44:02 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 18:07:31 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	nbr_len(int nbr)
{
	int count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*output;
	int		i;
	int		len;
	
	i = 0;
	len = nbr_len(nbr);
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	if (nbr == 0)
	{
		output[0] = '0';
		output[1] = '\0';
	}
	if (nbr < 0)
	{
		output[i] = '-';
		nbr *= -1;
	}
	i++;
	output[len--] = '\0';
	while (nbr)
	{
		output[len--] = nbr % 10 + '0';
		nbr /= 10; 
	}
	return (output);
}

int main()
{
	printf("%s", ft_itoa(-0));
	// printf("%d", nbr_len(-12));
	return (0);
}

// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);