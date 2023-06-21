/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:33:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:33:01 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}



#include <stdio.h>
#include <string.h>

int main()
{
	char	str1[5]  = "isfgd";
	char	str2[20] = "testing";

	strcpy(str1, str2);
	// ft_strcpy(str1, str2);
	printf("%s", str1);	
	return (0);
}


// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:

// char    *ft_strcpy(char *s1, char *s2);