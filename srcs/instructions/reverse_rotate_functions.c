/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:39:03 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:29:56 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	*ft_reverse_rotate_a(t_list2 **lst_A)
{
	if (!lst_A)
		return (NULL);
	if (ft_reverse_rotate(lst_A) == NULL)
		return (NULL);
	ft_printf("rra\n");
	return (NULL);
}

void	*ft_reverse_rotate_b(t_list2 **lst_B)
{
	if (!lst_B)
		return (NULL);
	if (ft_reverse_rotate(lst_B) == NULL)
		return (NULL);
	ft_printf("rrb\n");
	return (NULL);
}

void	*ft_reverse_rotate_ab(t_list2 **lst1, t_list2 **lst2)
{
	if (!lst1 || !lst2)
		return (NULL);
	if (ft_reverse_rotate(lst1) == NULL)
		return (NULL);
	if (ft_reverse_rotate(lst2) == NULL)
		return (NULL);
	ft_printf("rrr\n");
	return (NULL);
}

void	*ft_reverse_rotate(t_list2 **lst)
{
	t_list2	*temp;
	t_list2	*temp2;
	t_list2	*start;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		temp = *lst;
		temp2 = *lst;
		while (temp->next != NULL)
		{
			if (temp->next->next == NULL)
			{
				start = temp->next;
				temp->next = NULL;
			}
			else
				temp = temp->next;
		}
		start->next = (*lst)->next;
		*lst = start;
		(*lst)->next = temp2;
	}
	else
		return (NULL);
	return (lst);
}
