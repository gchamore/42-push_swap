/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 18:47:26 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Retourne la plus petite valeur dans la liste 'head_a'.
int	check_is_smallest(t_list **head_a)
{
	t_list	*lst;
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
int	count_lst(t_list **head)
{
	t_list	*lst;
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
int	search_position(t_list **head, int search)
{
	int		ct;
	t_list	*lst;
	
	lst = *head;
	ct = 1;
	while(lst != NULL)
	{
		if(lst->rank == search)
			return (ct);
		else
			lst = lst->next;
		ct++;
	}
	return (0);
}

// Vérifie si tous les éléments de la liste 'head_a'
// sont plus petits que 'rank_b'.
int	ft_sm(t_list **head_a, int rank_b)
{
	t_list	*lst;

	lst = *head_a;
	while (lst != NULL)
	{
		if (lst->rank < rank_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}

// Vérifie si tous les éléments de la liste 'head_a'
// sont plus grands que 'rank_b'.
int	ft_bg(t_list **head_a, int rank_b)
{
	t_list	*lst;

	lst = *head_a;
	while (lst != NULL)
	{
		if (lst->rank > rank_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}

// Retourne la valeur de rang la plus élevée dans la liste 'head'.
int	ft_last_rank(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->rank);
}

// Retourne la plus grande valeur dans la liste 'head'.
int	ft_big_a(t_list **head)
{
	t_list	*lst;
	int		save;

	lst = *head;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank > save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}

// Retourne la plus petite valeur dans la liste 'head'.
int	ft_small_a(t_list **head)
{
	t_list	*lst;
	int		save;

	lst = *head;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank < save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}
