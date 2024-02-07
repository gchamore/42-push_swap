/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 15:37:45 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

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

//compte le nombre d'element de la liste
int	count_lst(t_list **head)
{
	t_list	*lst;
	int count;

	lst = *head;
	count = 0;
    while (lst != NULL) 
	{
        count++;
		lst = lst->next;
    }
	return (count);
}

// Fonction qui retourne le nombre de place en dessous head ou se trouve search
int	search_position(t_list **head, int search)
{
	int	ct;
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

int	ft_check_if_small(t_list **head_a, int rank_b)
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

int	ft_check_if_big(t_list **head_a, int rank_b)
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

int		ft_last_rank(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->rank);
}

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