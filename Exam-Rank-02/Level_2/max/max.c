/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:37 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:38 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}


int main()
{
	int len = 5;
	int	tab[5] = {3, 2, 9, 7, 0};
	printf("%d", max(tab, 5));
	return (0);
}


// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.