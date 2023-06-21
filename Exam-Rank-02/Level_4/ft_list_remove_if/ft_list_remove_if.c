/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:21:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/01 07:58:26 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	tmp = (*begin_list);
	prev = NULL;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (cmp(tmp->data, data_ref) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				(*begin_list) = tmp->next;
			free(tmp);
			prev = NULL;
		}
		prev = tmp;
		tmp = next;
	}
	
}

#include <stdio.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String aa";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}

// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>





	// t_list *tmp;
	// t_list *next;
	// t_list *prev;

	// tmp = (*begin_list);
	// prev = NULL;
	// while (tmp)
	// {
	// 	next = tmp->next;
	// 	if (cmp(tmp->data, data_ref) == 0)
	// 	{
	// 		if (prev)
	// 			prev->next = tmp->next;
	// 		else
	// 			(*begin_list) = tmp->next;
	// 		free(tmp);
	// 	}
	// 	prev = tmp;
	// 	tmp = next;
	// }
