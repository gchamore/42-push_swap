/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:47 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:29:53 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	*ft_push_a(t_list2 **lst_B, t_list2 **lst_A)
{
	if (!lst_B)
		return (NULL);
	if (ft_push(lst_B, lst_A) == NULL)
		return (NULL);
	ft_printf("pa\n");
	return (NULL);
}

void	*ft_push_b(t_list2 **lst_A, t_list2 **lst_B)
{
	if (!lst_A)
		return (NULL);
	if (ft_push(lst_A, lst_B) == NULL)
		return (NULL);
	ft_printf("pb\n");
	return (NULL);
}

void	*ft_push(t_list2 **lst_1, t_list2 **lst_2)
{
	t_list2	*tmp;

	if (*lst_1 == NULL)
		return (NULL);
	tmp = *lst_1;
	*lst_1 = (*lst_1)->next;
	tmp->next = *lst_2;
	*lst_2 = tmp;
	return (lst_2);
}
