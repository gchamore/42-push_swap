/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:36:25 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 16:54:26 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int main (int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_lstnew();
	head_b = NULL;
	if (argc > 1)
	{
		head_a = ft_parse_a(argc, argv, head_a);
		if(!head_a)
			return (ft_free_lst(head_a), ft_free_lst(head_b),ft_error(), 0);
		ft_push_b(&head_a, &head_b);
		ft_push_b(&head_a, &head_b);
		ft_push_b(&head_a, &head_b);
		ft_push_a(&head_b, &head_a);

		ft_print_piles(head_a, head_b);
	}
	ft_free_lst(head_a);
	ft_free_lst(head_b);
	return (0);
}