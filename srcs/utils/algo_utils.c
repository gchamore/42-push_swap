/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:29:06 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Calcule les opérations totales pour chaque élément de la liste.
void	ft_calcul_ops_2(t_list2 *lst)
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

// Retourne la plus petite valeur dans la liste 'head_a'.
int	ft_check_is_smallest(t_list2 **head_a)
{
	t_list2	*lst;
	int		save;

	lst = *head_a;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank < save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}

// Compte le nombre d'éléments dans la liste.
int	ft_count_lst(t_list2 **head)
{
	t_list2	*lst;
	int		count;

	lst = *head;
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// Recherche la position d'une valeur donnée dans la liste.
int	ft_search_position(t_list2 **head, int search)
{
	int		ct;
	t_list2	*lst;

	lst = *head;
	ct = 1;
	while (lst != NULL)
	{
		if (lst->rank == search)
			return (ct);
		else
			lst = lst->next;
		ct++;
	}
	return (0);
}

// Retourne la valeur de rang la plus élevée dans la liste 'head'.
int	ft_last_rank(t_list2 **head)
{
	t_list2	*lst;

	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->rank);
}
