/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:20 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_inaccept(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (is_inaccept((char *)accept, s[i]))
			count++;
		else
			break ;
		i++;
	}
	return (count);
}


#include <stdio.h>
#include <string.h>

int main()
{
	printf("%lu\t", strspn("testaa", "abcdt"));
	printf("%lu\n", ft_strspn("testaa", "abcdt"));
	return (0);
}

// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);