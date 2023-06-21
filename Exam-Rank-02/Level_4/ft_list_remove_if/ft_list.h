/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:21:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/28 18:23:27 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

#include <unistd.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#endif