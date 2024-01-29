/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:38:33 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/29 14:06:30 by gchamore         ###   ########.fr       */
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
// 	printf("\n\n");
// 	pile_a = head_a;
// 	ft_swap(&pile_a);
// 	while (pile_a != NULL)
//     {
//     	printf("%ld, ", *pile_a->content);
// 		// printf("%d\n", *pile_a->rank);
//         pile_a = pile_a->next;
//     }
// 	ft_free_lst(head_a);
// }