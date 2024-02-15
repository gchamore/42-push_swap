/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:36:25 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:29:46 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_list2	*head_a;
	t_list2	*head_b;
	t_nbs	nbs;

	ft_init_struct(&nbs, &head_a, &head_b);
	if (argc > 1)
	{
		if (argc == 2)
			head_a = ft_parse_1_arg(argv, head_a);
		else
			head_a = ft_parse_a(argc, argv, head_a);
		if (!head_a)
			return (ft_error(), 0);
		ft_algo(&head_a, &head_b, &nbs);
	}
	ft_mod_free(head_a);
	ft_mod_free(head_b);
	return (0);
}
