/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:35:53 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int count;

	count = 0;
	if (!begin_list)
		return (0);
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	list = NULL;
	list = malloc(sizeof(t_list));
	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	if (!list || !node1 || !node2 || !node3)
		return (1);
	list->data = strdup("test1"); 
	node1->data = strdup("test2"); 
	node2->data = strdup("test3"); 
	node3->data = strdup("test4");
	list->next = node1;
	list->next->next = node2;
	list->next->next->next = node3; 
	printf("value is: %d\n", ft_list_size(list));
	return (0);
}
// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// :

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;