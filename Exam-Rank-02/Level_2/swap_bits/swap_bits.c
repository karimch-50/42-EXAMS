/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:52 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/16 11:19:51 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) & 0xFF | octet >> 4 & 0x00FF);
}

int main()
{
	printf("%d", swap_bits(10));
	return (0);
}

// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.

// Your function must be declared as follows:

// unsigned char	swap_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100 | 0001
//      \ /
//      / \
//  0001 | 0100