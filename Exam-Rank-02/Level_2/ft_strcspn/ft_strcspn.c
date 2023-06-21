/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:01 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	is_inreject(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_inreject((char *)reject, s[i]))
			return (i);
		i++;
	}
	return (i);
}

int main()
{
	printf("%lu\t", strcspn("abcd", "test"));
	printf("%lu\n", ft_strcspn("abcd", "test"));
	return (0);
}

// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);