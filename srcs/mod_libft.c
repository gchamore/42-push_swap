/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:51:17 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 15:17:31 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void ft_free_lst(t_list *lst)
{
	while (lst != NULL)
	{
		t_list *next;
		next = lst->next;
		
		if(lst->content)
			free(lst->content);
		if(lst->rank)
			free(lst->rank);
		if(lst)
			free(lst);
		lst = next;
	}
}

long int	ft_atol(const char *str)
{
	int	i;
	long int	total;
	long int	signe;
	
	total = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = signe * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i++] - '0');
	}
	return (total * signe);
}

void	*ft_lstlast(t_list **lst)
{
	if (lst)
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(lst);
		(*lst)->next = new;
		*lst = (*lst)->next;
		(*lst)->next = NULL;
	}
}