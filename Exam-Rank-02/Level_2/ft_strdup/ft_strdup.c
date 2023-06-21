/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:05 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:06 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char *output;
	int		i;

	output = malloc(ft_strlen(src));
	if (!output)
		return (NULL);
	i = 0;
	while (src[i])
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}


int main()
{
	printf("%s", ft_strdup("test"));
	return (0);
}
// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);