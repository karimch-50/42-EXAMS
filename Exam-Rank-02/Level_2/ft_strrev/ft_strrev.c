/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:13 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= (len / 2))
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		len --;
		i++;
	}
	return (str);
}

int main()
{
	char	str[5] = "karim";
	printf("%s", ft_strrev(str));
	return (0);
}

// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);