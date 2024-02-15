/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:53:02 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:30:02 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	*ft_rotate_a(t_list2 **lst_A)
{
	if (!lst_A)
		return (NULL);
	if (ft_rotate(lst_A) == NULL)
		return (NULL);
	ft_printf("ra\n");
	return (NULL);
}

void	*ft_rotate_b(t_list2 **lst_B)
{
	if (!lst_B)
		return (NULL);
	if (ft_rotate(lst_B) == NULL)
		return (NULL);
	ft_printf("rb\n");
	return (NULL);
}

void	*ft_rotate_ab(t_list2 **lst1, t_list2 **lst2)
{
	if (!lst1 || !lst2)
		return (NULL);
	if (ft_rotate(lst1) == NULL)
		return (NULL);
	if (ft_rotate(lst2) == NULL)
		return (NULL);
	ft_printf("rr\n");
	return (NULL);
}

void	*ft_rotate(t_list2 **lst)
{
	t_list2	*next_arg;
	t_list2	*start;

	if (*lst != NULL && (*lst)->next != NULL)
	{
		start = *lst;
		next_arg = (*lst)->next;
		*lst = next_arg;
		start->next = NULL;
		ft_mod_lstadd_back(lst, start);
	}
	else
		return (NULL);
	return (lst);
}
