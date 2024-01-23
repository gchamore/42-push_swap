/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:36:25 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/23 13:31:30 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int main (int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_lstnew(NULL);
	head_b = ft_lstnew(NULL);
	if (argc > 1)
	{
		ft_parse_a(argc, argv, head_a);
		// ft_push(&head_b, &head_a);
		ft_print_piles(head_a, head_b);
	}
	return (0);
}