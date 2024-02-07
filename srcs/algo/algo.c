/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 18:47:52 by gchamore         ###   ########.fr       */
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
	small = check_is_smallest(head);
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
	ct = count_lst(head_a);
	while (*head_a != NULL && ct-- > 3 && nbs->count > 3)
		ft_push_b(head_a, head_b);
	ft_tri_three_a(head_a);
}

// Trie les trois premiers éléments de la liste en ordre ascendant.
void	ft_tri_three_a(t_list **head_a)
{
	if (ft_is_sorted(head_a) == 1)
		return ;
	if ((*head_a)->rank > (*head_a)->next->rank)
		ft_swap_a(head_a);
	if ((*head_a)->next->rank > (*head_a)->next->next->rank)
	{
		ft_reverse_rotate_a(head_a);
		ft_swap_a(head_a);
	}
	if (ft_is_sorted(head_a) == 1)
		return ;
	if ((*head_a)->rank > (*head_a)->next->rank)
		ft_swap_a(head_a);
}

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
	middle = count_lst(head_b) / 2;
	while (lst2 != NULL)
	{
		lst1 = *head_a;
		ft_fill_ops_a(head_a, lst1, lst2);
		index = search_position(head_b, lst2->rank);
		if ((*head_b)->next != NULL)
		{
			if (index > middle)
				lst2->rrb = count_lst(head_b) - temp + 1;
			else
				lst2->rb = index - 1;
		}
		lst2 = lst2->next;
		temp++;
	}
}

// Vérifie si l'élément 'lst1' est le plus grand parmi les éléments 
// de 'head_a' et ajuste les opérations de rotation en conséquence.
int	ft_bg2(t_list **head_a, t_list *lst1, t_list *lst2, int temp)
{
	int	index;
	int	middle;

	middle = count_lst(head_a) / 2;
	index = search_position(head_a, lst1->rank);
	if (lst1->rank == ft_big_a(head_a))
	{
		if (index > middle)
			lst2->rra += count_lst(head_a) - temp;
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

	middle = count_lst(head_a) / 2;
	index = search_position(head_a, lst1->rank);
	if (lst1->rank == ft_small_a(head_a))
	{
		if (index > middle)
			lst2->rra += count_lst(head_a) - temp + 1;
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

	middle = count_lst(head_a) / 2;
	index = search_position(head_a, lst1->rank);
	if (lst2->rank < (*head_a)->rank && lst2->rank > ft_last_rank(head_a))
	{
		if (index > middle)
			lst2->rra += count_lst(head_a) - temp;
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

	middle = count_lst(head_a) / 2;
	index = search_position(head_a, lst1->rank);
	if (index > middle)
		lst2->rra += count_lst(head_a) - temp;
	else
		lst2->ra += index;
}

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

// Calcule les opérations totales pour chaque élément de la liste.
void	ft_calcul_ops_2(t_list *lst)
{
	while (lst->ra > 0 && lst->rra > 0)
	{
		lst->ra--;
		lst->rra--;
	}
	while (lst->rb > 0 && lst->rrb > 0)
	{
		lst->rb--;
		lst->rrb--;
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

// Place le plus petit élément de la liste 'head' au sommet de la pile.
void	ft_putsmallest_up(t_list **head)
{
	t_list	*lst;
	int		ct;
	int		middle;

	lst = *head;
	ct = lst->rank;
	middle = count_lst(head) / 2;
	while (lst != NULL)
	{
		if (lst->rank < ct)
			ct = lst->rank;
		lst = lst->next;
	}
	while ((*head)->rank != ct)
	{
		if (search_position(head, ct) > middle)
			ft_reverse_rotate_a(head);
		else
			ft_rotate_a(head);
	}
}
