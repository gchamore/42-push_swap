/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:33:57 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 16:39:02 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

int	ft_do_swp_and_psh(t_list2 **head_a, t_list2 **head_b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", ft_strlen(instruction)) == 0)
		ft_swap(head_a);
	else if (ft_strncmp(instruction, "sb\n", ft_strlen(instruction)) == 0)
		ft_swap(head_b);
	else if (ft_strncmp(instruction, "ss\n", ft_strlen(instruction)) == 0)
	{
		ft_swap(head_a);
		ft_swap(head_b);
	}
	else if (ft_strncmp(instruction, "pa\n", ft_strlen(instruction)) == 0)
		ft_push(head_b, head_a);
	else if (ft_strncmp(instruction, "pb\n", ft_strlen(instruction)) == 0)
		ft_push(head_a, head_b);
	else
		return (0);
	return (1);
}

int	ft_do_rot_and_revrot(t_list2 **head_a, t_list2 **head_b, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", ft_strlen(instruction)) == 0)
		ft_rotate(head_a);
	else if (ft_strncmp(instruction, "rb\n", ft_strlen(instruction)) == 0)
		ft_rotate(head_b);
	else if (ft_strncmp(instruction, "rr\n", ft_strlen(instruction)) == 0)
	{
		ft_rotate(head_a);
		ft_rotate(head_b);
	}
	else if (ft_strncmp(instruction, "rra\n", ft_strlen(instruction)) == 0)
		ft_reverse_rotate(head_a);
	else if (ft_strncmp(instruction, "rrb\n", ft_strlen(instruction)) == 0)
		ft_reverse_rotate(head_b);
	else if (ft_strncmp(instruction, "rrr\n", ft_strlen(instruction)) == 0)
	{
		ft_reverse_rotate(head_a);
		ft_reverse_rotate(head_b);
	}
	else
		return (0);
	return (1);
}

int	ft_do_instructions(t_list2 **head_a, t_list2 **head_b, char *instruction)
{
	int	check1;
	int	check2;

	check1 = 1;
	check2 = 1;
	check1 = ft_do_swp_and_psh(head_a, head_b, instruction);
	check2 = ft_do_rot_and_revrot(head_a, head_b, instruction);
	if (check1 == 0 && check2 == 0)
		return (free(instruction), ft_error(), 0);
	return (1);
}

int	verif_instructions(t_list2 **head_a, t_list2 **head_b)
{
	char	*line;

	line = NULL;
	if (ft_is_sorted(head_a) == 1 && *head_b == NULL)
	{
		ft_printf("OK\n");
		return (1);
	}
	line = ft_get_next_line(0);
	while (line != NULL)
	{
		if (ft_do_instructions(head_a, head_b, line) == 0)
			return (0);
		free(line);
		line = ft_get_next_line(0);
	}
	if (ft_is_sorted(head_a) == 1 && *head_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_list2	*head_a;
	t_list2	*head_b;
	t_nbs	nbs;

	if (argc == 1)
		return (0);
	ft_init_struct(&nbs, &head_a, &head_b);
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (ft_check_only_spaces(argv[1]) == 1 || \
			ft_check_null(argv[1]) == 1)
				return (free(head_a), ft_error(), 0);
			head_a = ft_parse_1_arg(argv, head_a);
		}
		else
			head_a = ft_parse_a(argc, argv, head_a);
		if (!head_a)
			return (ft_error(), 0);
		verif_instructions(&head_a, &head_b);
	}
	return (ft_mod_free(head_a), ft_mod_free(head_b), 0);
}
