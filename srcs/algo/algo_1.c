/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 16:07:44 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Applique l'algorithme de tri push_swap en utilisant
// les fonctions auxiliaires.
void	ft_algo(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	if (ft_is_sorted(head_a) == 0)
	{
		ft_fill_struct(head_a, nbs);
		ft_algo_pre_tri(head_a, head_b, nbs);
		while (*head_b != NULL)
		{
			ft_reset_ops(head_b);
			ft_fill_ops(head_a, head_b);
			ft_calcul_ops(head_b);
			ft_exec_ops(head_a, head_b);
		}
		ft_putsmallest_up(head_a);
	}
}

// Vérifie si la liste est triée dans l'ordre ascendant.
int	ft_is_sorted(t_list **head)
{
	t_list	*lst;
	int		small;

	lst = *head;
	small = ft_check_is_smallest(head);
	if (lst->rank != small)
		return (0);
	while (lst != NULL)
	{
		if (lst->rank != small)
			return (0);
		lst = lst->next;
		small++;
	}
	return (1);
}

// Applique une série d'opérations sur la liste pour pré-trier les éléments.
void	ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	check;
	int	ct;

	check = nbs->count;
	if (check <= 3)
		ft_tri_three_a(head_a);
	while (*head_a != NULL && check >= 1 && nbs->count > 3)
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
	ct = ft_count_lst(head_a);
	while (*head_a != NULL && ct-- > 3 && nbs->count > 3)
		ft_push_b(head_a, head_b);
	ft_tri_three_a(head_a);
}

// Trie les trois premiers éléments de la liste en ordre ascendant.
void	ft_tri_three_a(t_list **head_a)
{
	if (ft_is_sorted(head_a) == 0)
	{
		if ((*head_a)->rank > (*head_a)->next->rank)
			ft_swap_a(head_a);
	}
	if (ft_is_sorted(head_a) == 0)
	{
		if ((*head_a)->next->rank > (*head_a)->next->next->rank)
		{
			ft_reverse_rotate_a(head_a);
			if (ft_is_sorted(head_a) == 0)
				ft_swap_a(head_a);
		}
	}
	if (ft_is_sorted(head_a) == 0)
	{
		if ((*head_a)->rank > (*head_a)->next->rank)
			ft_swap_a(head_a);
	}
}

// Place le plus petit élément de la liste 'head' au sommet de la pile.
void	ft_putsmallest_up(t_list **head)
{
	t_list	*lst;
	int		ct;
	int		middle;

	lst = *head;
	ct = lst->rank;
	middle = ft_count_lst(head) / 2;
	while (lst != NULL)
	{
		if (lst->rank < ct)
			ct = lst->rank;
		lst = lst->next;
	}
	while ((*head)->rank != ct)
	{
		if (ft_search_position(head, ct) > middle)
			ft_reverse_rotate_a(head);
		else
			ft_rotate_a(head);
	}
}
