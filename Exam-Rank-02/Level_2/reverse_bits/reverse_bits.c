/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:46 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	res = 0;
	i = 0;
	while (i < 7)
	{
		res = res | (((octet >> i) & 1) << (8 - i));
		i++;
	}
	return (res);
}

int main()
{
	printf("%d", reverse_bits(20));
	return (0);
}

// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100