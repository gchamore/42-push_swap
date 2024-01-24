/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:24 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 15:39:42 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the arg_1 2 elements at the top of the stack a. Does nothing if there is only one or none. 
// sb (swap b) : Swap the arg_1 2 elements at the top of the stack b. Does nothing if there is only one or none. 
// ss : sa and sb at the same time.

#include "../headers/push_swap.h"

void	*ft_swap_a(t_list **lst_A)
{
	if(!lst_A)
		return (NULL);
	if (ft_swap(lst_A) == NULL)
		return (NULL);
	printf("sa\n");
	return (NULL);
}

void	*ft_swap_b(t_list **lst_B)
{
	if(!lst_B)
		return (NULL);
	if (ft_swap(lst_B) == NULL)
		return (NULL);
	printf("sb\n");
	return (NULL);
}

void	*ft_swap_ab(t_list **lst1, t_list **lst2)
{
	if(!lst1 || !lst2)
		return (NULL);
	if (ft_swap(lst1) == NULL)
		return (NULL);
	if (ft_swap(lst2) == NULL)
		return (NULL);
	printf("ss\n");
	return (NULL);
}
void	*ft_swap(t_list **lst)
{
	t_list *arg_1;
    t_list *arg_2;
	
    if (*lst != NULL || (*lst)->next != NULL)
    {
		arg_1 = *lst;
		arg_2 = (*lst)->next;
        arg_1->next = arg_2->next;
        arg_2->next = arg_1;
        *lst = arg_2;
    }
	else
		return (NULL);
	return (lst);
}