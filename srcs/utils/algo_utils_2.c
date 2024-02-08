/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:22:27 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/08 10:24:24 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

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

void	ft_error(void)
{
	write(1, "Error\n", 6);
}
