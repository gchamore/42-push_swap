/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:49 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:28:52 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Attribue un rang à chaque élément de la liste 'head_a' en
// fonction de sa valeur par rapport aux autres éléments.
void	ft_ranking(t_list2 *head_a, t_list2 *pile_a)
{
	t_list2	*lst;
	int		rank_count;

	pile_a = head_a;
	lst = head_a;
	rank_count = 1;
	while (lst != NULL)
	{
		pile_a = head_a;
		rank_count = 1;
		while (pile_a != NULL)
		{
			if (lst->content > pile_a->content)
				rank_count += 1;
			pile_a = pile_a->next;
		}
		lst->rank = rank_count;
		lst = lst->next;
	}
}

// Vérifie si la liste contient des doublons ou des valeurs
// qui dépassent la plage d'un entier signé 32 bits.
int	ft_int_check_lst(t_list2 *lst, long int *search)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		if ((lst->content > 2147483647) || (lst->content < -2147483648))
			return (1);
		if (lst->content == *search)
		{
			count += 1;
			if (count > 1)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

// Vérifie la validité de la chaîne de caractères 'str' et la
// convertit en un pointeur sur char si elle est valide.
void	*ft_str_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] != '-' && str[i] != '+' && \
	(str[i] < '0' || str[i] > '9')))
		return (NULL);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		i++;
		if (str[i] == '\0' && (str[i] < '0' || str[i] > '9'))
			return (NULL);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (NULL);
	return (str);
}

// Convertit la chaîne de caractères 'str' en un élément de la
// liste 'pile_a' et vérifie sa validité.
void	*ft_parse_one_arg(t_list2 *head_a, t_list2 *pile_a, char *str)
{
	int		len;

	if (!str)
		return (ft_mod_free(head_a), NULL);
	len = 0;
	str = ft_str_check(str);
	if (!str)
		return (ft_mod_free(head_a), NULL);
	pile_a->content = ft_mod_atol(str);
	if (ft_int_check_lst(head_a, &pile_a->content))
		return (ft_mod_free(head_a), NULL);
	return (pile_a);
}

// Analyse les arguments passés en entrée et les convertit en éléments
// de la liste 'head_a'.
void	*ft_parse_a(int argc, char **argv, t_list2 *head_a)
{
	int		y;
	char	*str;
	t_list2	*pile_a;

	y = 1;
	pile_a = head_a;
	while (y < argc)
	{
		str = argv[y];
		pile_a = ft_parse_one_arg(head_a, pile_a, str);
		if (!pile_a)
			return (NULL);
		if (y < argc - 1)
		{
			pile_a->next = ft_mod_new_lst();
			if (!pile_a->next)
				return (NULL);
			pile_a = pile_a->next;
		}
		y++;
	}
	return (ft_ranking(head_a, pile_a), head_a);
}
