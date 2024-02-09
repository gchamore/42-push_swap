/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:33:57 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 15:56:49 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// recuperer la liste a.

// verifier si liste d'entier

// Si aucun argument n’est donné, le programme s’arrête
// et n’affiche rien.

// Il doit ensuite attendre et lire des instructions sur 
// l’entrée standard, chaque instruction suivie par un ’\n’. 
// Une fois toutes les instructions lues, le programme va
// les exécuter sur la pile d’entiers passée en paramètre.

// Si à la suite de l’exécution la pile a est bien triée et 
// la pile b est vide, alors le programme doit afficher "OK" 
// suivi par un ’\n’ sur la sortie standard.

// Sinon, il doit afficher "KO" suivi par un ’\n’ sur la 
// sortie standard.

// En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’
// sur la sortie d’erreur. Par exemple, si certains paramètres
// ne sont pas des nombres, ne tiennent pas dans un int, s’il 
// y a des doublons ou, bien sûr, si une instruction n’existe
// pas ou est mal formatée.

#include "../headers/push_swap.h"

int	ft_do_swp_and_psh(t_list **head_a, t_list **head_b, char *instruction)
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

int	ft_do_rot_and_revrot(t_list **head_a, t_list **head_b, char *instruction)
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

int	ft_do_instructions(t_list **head_a, t_list **head_b, char *instruction)
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

int	verif_instructions(t_list **head_a, t_list **head_b)
{
	char	*line;

	line = NULL;
	if (ft_is_sorted(head_a) == 1 && *head_b == NULL)
	{
		printf("OK\n");
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
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	t_nbs	nbs;

	if (argc == 1)
		return (0);
	ft_init_struct(&nbs, &head_a, &head_b);
	if (argc > 1)
	{
		if (argc == 2)
			head_a = ft_parse_1_arg(argv, head_a);
		else
			head_a = ft_parse_a(argc, argv, head_a);
		if (!head_a)
			return (ft_error(), 0);
		verif_instructions(&head_a, &head_b);
		ft_mod_free(head_a);
		ft_mod_free(head_b);
	}
	return (0);
}
