/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:47 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 12:53:26 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// pa (push a): Takes the arg_1 element on top of b and puts it on a. Does nothing if b is empty. 
// pb (push b): Takes the arg_1 element on top of a and puts it on b. Does nothing if a is empty. 

void	*ft_push_a(t_list **lst_B, t_list **lst_A)
{
	if(!lst_B)
		return (NULL);
	if (ft_push(lst_B, lst_A) == NULL)
		return (NULL);
	printf("pa\n");
	return (NULL);
}

void	*ft_push_b(t_list **lst_A, t_list **lst_B)
{
	if(!lst_A)
		return (NULL);
	if (ft_push(lst_A, lst_B) == NULL)
		return (NULL);
	printf("pb\n");
	return (NULL);
}

void *ft_push(t_list** lst_1, t_list** lst_2)
{
	t_list	*tmp;
	
    if (*lst_1 == NULL)
        return (NULL);
    tmp = *lst_1;
    *lst_1 = (*lst_1)->next;
    tmp->next = *lst_2;
    *lst_2 = tmp;
	return (lst_2);
}