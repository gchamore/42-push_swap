/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/29 13:51:49 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	algo_pre_tri(t_list **head_a, t_list **head_b, nbs *nbs)
{
	int		check;
	
	check = nbs->count;
	printf("\n\n&&nb de RANK %d&&\n\n", nbs->count);
	while(*head_a != NULL && check >= 1)
	{
		if ((*head_a)->rank > nbs->div1 && ((*head_a)->rank <= nbs->div2))
			ft_push_b(head_a, head_b);
		else if ((*head_a)->rank <= nbs->div1)
		{
			ft_push_b(head_a, head_b);
			ft_rotate_b(head_b);
		}
		else
			ft_rotate_a(head_a);
		check--;
	}
	while(*head_a != NULL)
		ft_push_b(head_a, head_b);
}

// void	insertion_sort(t_list **head_a, t_list **head_b)
// {
	
// }