/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:17:47 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/22 17:03:15 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_push_a(t_list *lst1, t_list *lst2)
{
	ft_push(&lst1, &lst2);
	printf("pa");
}

void	ft_push_b(t_list *lst1, t_list *lst2)
{
	ft_push(&lst1, &lst2);
	printf("pb");
}

void	add_node(t_list **head)
{
	t_list *lst;
	
	if (!head)
		return ;
	lst = ft_lstnew(NULL);
	lst->next = *head;
	*head = lst;
	
}

void ft_push(t_list **lst_b, t_list **lst_a)
{
	t_list *new_node;
	t_list *temp;
	
    if (lst_a != NULL && *lst_a != NULL)
    {
        new_node->content = ft_lstnew((*lst_a)->content);
        new_node->next = *lst_b;
        lst_b = &new_node;
		printf("%d", lst_b);
		
		temp = *lst_a;
        *lst_a = (*lst_a)->next;
        free(temp->content);
        free(temp);
    }
}
// erreur a refaire.