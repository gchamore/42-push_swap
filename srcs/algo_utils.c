/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/01 17:32:34 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

int	which_part(t_list **head, int search)
{
	int	med;
	int total;
	t_list	*lst;
	
	lst = *head;
	total = count_lst(head);
	if (total == 1)
		return 3;
	med = total/2;
	while(lst != NULL && total > med)
	{
		if(search == lst->rank)
			return 1;
		else
			lst = lst->next;
		total--;
	}
	while(lst != NULL && total <= med)
	{
		if(search == lst->rank)
			return 2;
		else
			lst = lst->next;
		total--;
	}
	return 0;
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

// Fonction qui a pour but de comparer l'efficacite de deux 
// algo en terme de nombre de moove.

// int	ft_compare(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
	
// }

// Fonction qui va mettre search en premiere position avec des rotates

void	ft_put_search_first_a(t_list **head_a, int search)
{
	t_list	*lst;
	
	lst = *head_a;
	while(lst != NULL)
	{
		if (lst->rank == search)
		{
			if (which_part(head_a, search) == 3)
				return ;
			else if (which_part(head_a, search) == 2)
			{
				while ((*head_a)->rank != search)
					ft_reverse_rotate_a(head_a);
				
			}
			else if (which_part(head_a, search) == 1)
			{
				while ((*head_a)->rank != search)
					ft_rotate_a(head_a);
			}
			return ;
		}
		else
			lst = lst->next;
	}
}
