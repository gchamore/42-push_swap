#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef	struct s_list
{
	long int		*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

#endif