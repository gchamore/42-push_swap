/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:38:33 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/01 13:49:13 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_print_piles(t_list *head_a, t_list *head_b)
{
	t_list	*pile_a;
	t_list	*pile_b;
	
	pile_a = head_a;
	pile_b = head_b;
	ft_printf("\nPILE A = \n");
	while (pile_a != NULL)
    {
    	// ft_printf("%d, ", pile_a->content);
		ft_printf("%d, ", pile_a->rank);
        pile_a = pile_a->next;
    }
	ft_printf("\n\nPILE B = \n");
	while (pile_b != NULL)
    {
    	// ft_printf("%d, ", pile_b->content);
		ft_printf("%d, ", pile_b->rank);
        pile_b = pile_b->next;
    }
}
