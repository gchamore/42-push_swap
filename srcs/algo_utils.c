/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 14:42:16 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

int	ft_is_sorted(t_list **head)
{
	t_list *lst;
	int	small;

	lst = *head;
	small = check_is_smallest(head);
	while(lst != NULL)
	{
		if (lst->rank != small)
			return (0);
		if(lst->rank > lst->next->rank)
			return (0);
		lst = lst->next;
	}
	return (1);
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
// definie si search se trouve dans la premiere moitiee
// ou la seconde afin de savoir si il vaut mieux rotate 
// ou reverse rotate.

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

