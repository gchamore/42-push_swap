/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:03:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 15:37:42 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_fill_struct(t_list **head, t_nbs *nbs)
{
	t_list	*lst;

	lst = *head;
	nbs->count = 0;
    while (lst != NULL) 
	{
        nbs->count++;
		lst = lst->next;
    }
	nbs->div1 = (nbs->count/3);
	nbs->div2 = ((nbs->count/3)*2);
}

void	*ft_init_struct(t_nbs *nbs, t_list **head_a, t_list **head_b)
{
	nbs->count = 0;
	nbs->div1 = 0;
	nbs->div2 = 0;
	*head_a = ft_mod_new_lst();
	if(!head_a)
		return NULL;
	*head_b = NULL;
	return(head_a);
}
