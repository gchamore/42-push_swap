/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:27:50 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:50 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Remplit les opérations associées aux éléments de la liste 'head_b' en
// fonction de leur position par rapport aux éléments de la liste 'head_a'.
void	ft_fill_ops_a(t_list **head_a, t_list *lst1, t_list *lst2)
{
	int	temp;

	temp = 1;
	while (lst1 != NULL)
	{
		if (lst2->rank < (*head_a)->rank && lst2->rank > ft_last_rank(head_a))
		{
			if (ft_check_one_and_last(head_a, lst1, lst2, temp) == 1)
				break ;
		}
		else if (ft_bg(head_a, lst2->rank) > 0 || ft_sm(head_a, lst2->rank) > 0)
		{
			if (ft_bg2(head_a, lst1, lst2, temp) == 1 || \
			ft_sm2(head_a, lst1, lst2, temp) == 1)
				break ;
		}
		else if (lst1->next != NULL && lst2->rank > lst1->rank \
		&& lst2->rank < lst1->next->rank)
		{
			ft_check_rank_and_next(head_a, lst1, lst2, temp);
			break ;
		}
		lst1 = lst1->next;
		temp++;
	}
}

// Vérifie si l'élément 'lst1' est le plus grand parmi les éléments 
// de 'head_a' et ajuste les opérations de rotation en conséquence.
int	ft_bg2(t_list **head_a, t_list *lst1, t_list *lst2, int temp)
{
	int	index;
	int	middle;

	middle = ft_count_lst(head_a) / 2;
	index = ft_search_position(head_a, lst1->rank);
	if (lst1->rank == ft_big_a(head_a))
	{
		if (index > middle)
			lst2->rra += ft_count_lst(head_a) - temp;
		else
			lst2->ra += index;
		return (1);
	}
	return (0);
}

// Vérifie si l'élément 'lst1' est le plus petit parmi les éléments
// de 'head_a' et ajuste les opérations de rotation en conséquence.
int	ft_sm2(t_list **head_a, t_list *lst1, t_list *lst2, int temp)
{
	int	index;
	int	middle;

	middle = ft_count_lst(head_a) / 2;
	index = ft_search_position(head_a, lst1->rank);
	if (lst1->rank == ft_small_a(head_a))
	{
		if (index > middle)
			lst2->rra += ft_count_lst(head_a) - temp + 1;
		else
			lst2->ra += index - 1;
		return (1);
	}
	return (0);
}

// Vérifie si l'élément 'lst2' est placé à l'extrémité de la liste 'head_a'
// et ajuste les opérations de rotation en conséquence.
int	ft_check_one_and_last(t_list **head_a, t_list *lst1, t_list *lst2, int temp)
{
	int	index;
	int	middle;

	middle = ft_count_lst(head_a) / 2;
	index = ft_search_position(head_a, lst1->rank);
	if (lst2->rank < (*head_a)->rank && lst2->rank > ft_last_rank(head_a))
	{
		if (index > middle)
			lst2->rra += ft_count_lst(head_a) - temp;
		else
			lst2->ra += index - 1;
		return (1);
	}
	return (0);
}

// Vérifie la position de 'lst1' dans la liste 'head_a' et ajuste
// les opérations de rotation en conséquence.
void	ft_check_rank_and_next(t_list **head_a, t_list *lst1, \
t_list *lst2, int temp)
{
	int	index;
	int	middle;

	middle = ft_count_lst(head_a) / 2;
	index = ft_search_position(head_a, lst1->rank);
	if (index > middle)
		lst2->rra += ft_count_lst(head_a) - temp;
	else
		lst2->ra += index;
}
