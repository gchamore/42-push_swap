/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:36:25 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/29 17:08:54 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int main (int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	nbs		nbs;
	
	init_struct(&nbs, &head_a, &head_b);
	if (argc > 1)
	{
		if(argc == 2)
			head_a = ft_parse_1_arg(argv, head_a);
		else
			head_a = ft_parse_a(argc, argv, head_a);
		if(!head_a)
			return (ft_free(head_a), ft_error(), 0);
		ft_print_piles(head_a, head_b);
		ft_printf("\n---------------------------------------------------------- \n");
		fill_struct(&head_a, &nbs);
		algo_pre_tri(&head_a, &head_b, &nbs);
		ft_printf("\n---------------------------------------------------------- \n");
		// ft_print_piles(head_a, head_b);
		// insertion_sort(&head_a, &head_b);
		ft_print_piles(head_a, head_b);
	}
	ft_free(head_a);
	ft_free(head_b);
	return (0);
}
