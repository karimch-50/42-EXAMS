#ifndef FT_LIST_H
# define FT_LIST_H

#include <unistd.h>

typedef struct    s_list
{
    void			*data;
    struct s_list	*next;
}	t_list;

#endif