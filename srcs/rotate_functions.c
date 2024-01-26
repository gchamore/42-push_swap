/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:53:02 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/26 15:21:21 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// ra (rotate a): Shifts all the elements of the stack a up by one position. The start element becomes the last. 
// rb (rotate b) : Shifts all the elements of the stack b one position upwards. The start element becomes the last one. 
// rr : ra and rb at the same time. 

void	*ft_rotate_a(t_list **lst_A)
{
	if(!lst_A)
		return (NULL);
	if (ft_rotate(lst_A) == NULL)
		return (NULL);
	ft_printf("ra\n");
	return (NULL);
}

void	*ft_rotate_b(t_list **lst_B)
{
	if(!lst_B)
		return (NULL);
	if (ft_rotate(lst_B) == NULL)
		return (NULL);
	ft_printf("rb\n");
	return (NULL);
}

void	*ft_rotate_ab(t_list **lst1, t_list **lst2)
{
	if(!lst1 || !lst2)
		return (NULL);
	if (ft_rotate(lst1) == NULL)
		return (NULL);
	if (ft_rotate(lst2) == NULL)
		return (NULL);
	ft_printf("rr\n");
	return (NULL);
}

void	*ft_rotate(t_list **lst)
{
    t_list	*next_arg;
	t_list	*start;

    if (*lst != NULL && (*lst)->next != NULL)
    {
		start = *lst;
		next_arg = (*lst)->next;
		*lst = next_arg;
		start->next = NULL;
		ft_lstadd_back(lst, start);
    }
	else
		return (NULL);
	return (lst);
}