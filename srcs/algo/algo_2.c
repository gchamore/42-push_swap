/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:27:47 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 12:58:56 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Réinitialise les opérations associées aux éléments de la liste.
void	ft_reset_ops(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst != NULL)
	{
		lst->pa = 1;
		lst->ra = 0;
		lst->rb = 0;
		lst->rr = 0;
		lst->rra = 0;
		lst->rrb = 0;
		lst->rrr = 0;
		lst->total = 0;
		lst = lst->next;
	}
}

// Remplit les opérations associées aux éléments de la liste 'head_b'.
void	ft_fill_ops(t_list **head_a, t_list **head_b)
{
	t_list	*lst1;
	t_list	*lst2;
	int		index;
	int		middle;
	int		temp;

	lst1 = *head_a;
	lst2 = *head_b;
	temp = 1;
	middle = ft_count_lst(head_b) / 2;
	while (lst2 != NULL)
	{
		lst1 = *head_a;
		ft_fill_ops_a(head_a, lst1, lst2);
		index = ft_search_position(head_b, lst2->rank);
		if ((*head_b)->next != NULL)
		{
			if (index > middle)
				lst2->rrb = ft_count_lst(head_b) - temp + 1;
			else
				lst2->rb = index - 1;
		}
		lst2 = lst2->next;
		temp++;
	}
}

// Calcule les opérations totales pour chaque élément de la liste.
void	ft_calcul_ops(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst != NULL)
	{
		ft_calcul_ops_2(lst);
		while (lst->ra > 0 && lst->rb > 0)
		{
			lst->rr++;
			lst->ra--;
			lst->rb--;
		}
		while (lst->rra > 0 && lst->rrb > 0)
		{
			lst->rrr++;
			lst->rra--;
			lst->rrb--;
		}
		lst->total = lst->pa + lst->ra + lst->rb + lst->rr + \
		lst->rra + lst->rrb + lst->rrr;
		lst = lst->next;
	}
}

// Exécute les opérations avec le moins de mouvements totaux possibles.
void	ft_exec_ops(t_list **head_a, t_list **head_b)
{
	t_list	*lst;
	t_list	*save;

	lst = *head_b;
	save = lst;
	while (lst != NULL)
	{
		if (lst->total < save->total)
			save = lst;
		lst = lst->next;
	}
	ft_do_ops(&save, head_a, head_b);
}

// Effectue les opérations spécifiées sur les listes 'head_a' et 'head_b'.
void	ft_do_ops(t_list **head, t_list **head_a, t_list **head_b)
{
	t_list	*lst;

	lst = *head;
	while (lst->rr-- > 0)
		ft_rotate_ab(head_a, head_b);
	while (lst->rrr-- > 0)
		ft_reverse_rotate_ab(head_a, head_b);
	while (lst->ra-- > 0)
		ft_rotate_a(head_a);
	while (lst->rb-- > 0)
		ft_rotate_b(head_b);
	while (lst->rra-- > 0)
		ft_reverse_rotate_a(head_a);
	while (lst->rrb-- > 0)
		ft_reverse_rotate_b(head_b);
	while (lst->pa-- > 0)
		ft_push_a(head_b, head_a);
}
