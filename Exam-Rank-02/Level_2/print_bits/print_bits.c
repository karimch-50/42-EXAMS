/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:41 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:42 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

void	print_bits(unsigned char octet)
{
	int i;
	unsigned char out;

	i = 7;
	while (i > -1)
	{
		out = ((octet >> i) & 1) + '0';
		write(1, &out, 1);
		i--;
	}
}

int main()
{
	print_bits(76);
	return (0);
}

// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"