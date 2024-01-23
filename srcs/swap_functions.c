/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:24 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/22 15:15:43 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
// sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 
// ss : sa and sb at the same time. 
// pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 
// pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 
// ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 
// rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 
// rr : ra and rb at the same time. 
// rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 
// rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 
// rrr : rra and rrb at the same time.

#include "../headers/push_swap.h"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_swap_a(t_list *lst)
{
	ft_swap(&lst);
	ft_printf("sa");
}

void	ft_swap_b(t_list *lst)
{
	ft_swap(&lst);
	ft_printf("sb");
}

void	ft_swap_ab(t_list *lst1, t_list *lst2)
{
	ft_swap(&lst1);
	ft_swap(&lst2);
	ft_printf("ss");
}
void	ft_swap(t_list **lst)
{
    if (*lst != NULL && (*lst)->next != NULL)
    {
        t_list *first = *lst;
        t_list *second = (*lst)->next;

        first->next = second->next;
        second->next = first;
        *lst = second;
    }
}