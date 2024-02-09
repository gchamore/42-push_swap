/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:24 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 15:06:10 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	*ft_swap_a(t_list **lst_A)
{
	if (!lst_A)
		return (NULL);
	if (ft_swap(lst_A) == NULL)
		return (NULL);
	ft_printf("sa\n");
	return (NULL);
}

void	*ft_swap_b(t_list **lst_B)
{
	if (!lst_B)
		return (NULL);
	if (ft_swap(lst_B) == NULL)
		return (NULL);
	ft_printf("sb\n");
	return (NULL);
}

void	*ft_swap_ab(t_list **lst1, t_list **lst2)
{
	if (!lst1 || !lst2)
		return (NULL);
	if (ft_swap(lst1) == NULL)
		return (NULL);
	if (ft_swap(lst2) == NULL)
		return (NULL);
	ft_printf("ss\n");
	return (NULL);
}

void	*ft_swap(t_list **lst)
{
	t_list	*arg_1;
	t_list	*arg_2;

	if (*lst != NULL && (*lst)->next != NULL)
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
