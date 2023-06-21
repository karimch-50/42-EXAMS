/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:36:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 12:35:05 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	*output;
	int	count;
	int	i;

	if (start == end)
		count = 1;
	else if (start < end)
		count = abs(end - start) + 1;
	else
		count = abs(start - end) + 1;
	output = malloc(sizeof(int) * count);
	i = 0;
	if (!output)
		return (NULL);
	if (start < end)
	{
		while (i < count)
			output[i++] = end--;
	}
	else
		while (i < count)
			output[i++] = end++;
	
	return (output);
}

int main()
{
	int *rrange = ft_rrange(0, -3);
	int i;

	i = 0;
	while (i < 4)
		printf("%d\n", rrange[i++]);
	return (0);
}

// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.