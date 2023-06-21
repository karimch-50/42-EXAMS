/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:35:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

long long unsigned	my_abs(long long unsigned nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	*ft_range(int start, int end)
{
	int	*output;
	long long unsigned	i;
	long long unsigned	count;

	if (start == end)
		count = 1;
	else if (start < end)
		count = my_abs((long long unsigned)end - (long long unsigned)start) + 1;
	else
		count = my_abs((long long unsigned)start - (long long unsigned)end) + 1;
	output = malloc(sizeof(int) * count);
	if (!output)
		return (NULL);
	i = 0;
	if (start == end)
		output[i] = start;
	else if (start < end)
	{
		while (i < count)
			output[i++] = start++;
	}
	else
	{
		while (i < count)
			output[i++] = start--;
	}
	return (output);
}


int main()
{
	int	*range = ft_range(0, -3);
	int i = 0;
	while (i < 10)
		printf("%d\n", range[i++]);
	return (0);
}




// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.