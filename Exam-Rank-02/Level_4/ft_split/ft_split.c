/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:36:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 17:06:36 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

char	*get_word(char *str)
{
	char *output;
	int count;
	int i;

	count = 0;
	while (str[count] && str[count] != ' ')
		count++;
	output = malloc(count + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char    **ft_split(char *str)
{
	char	**output;
	int		i;
	int		j;

	output = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			output[j++] = get_word(&str[i]);
		while (str[i] && str[i] != ' ')
		i++;
	}
	output[j] = NULL;
	return (output);	
}

int main()
{
	// printf("%d\n", count_words("dwfwerfgt			wefwfv3"));
	char **split = ft_split("            test     test2test3est4          ");
	int i = 0;
	while (split[i])
		printf("%s\n", split[i++]);
	return (0);
}

// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);