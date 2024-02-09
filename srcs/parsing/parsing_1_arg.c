/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:57:19 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/09 12:56:52 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// Libère la mémoire allouée pour un tableau de chaînes de
// caractères et pour les chaînes de caractères elles-mêmes.
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

// Compte le nombre de lignes dans un tableau de chaînes de caractères.
int	ft_count_rows(char	**tab)
{
	int	row_count;

	row_count = 0;
	while (tab[row_count] != NULL)
	{
		row_count++;
	}
	return (row_count);
}

// Vérifie et découpe une chaîne de caractères 'str' en sous-chaînes
// en fonction des espaces, des tabulations et des sauts de ligne.
void	*ft_verif_str(char **split, char *str)
{
	int	row;
	int	collum;

	row = 0;
	while (*str)
	{
		collum = 0;
		split[row] = (char *)malloc(sizeof(char) * (ft_one_word_len(str) + 1));
		if (!split[row])
			return (NULL);
		while (*str && !ft_is_delimiter(*str))
		{
			split[row][collum] = *str;
			str++;
			collum++;
		}
		while (*str && ft_is_delimiter(*str))
			str++;
		split[row][collum] = '\0';
		row++;
	}
	split[row] = NULL;
	return (split);
}

// Découpe une chaîne de caractères en sous-chaînes en fonction
// des espaces, des tabulations et des sauts de ligne.
char	**ft_split(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_words_count(str) + 1));
	if (!split)
		return (NULL);
	while (ft_is_delimiter(*str))
		str++;
	split = ft_verif_str(split, str);
	if (!split)
		return (free(split), NULL);
	return (split);
}

// Analyse un seul argument et l'ajoute à la liste 'head_a', en
// le découpant en sous-chaînes si nécessaire.
void	*ft_parse_1_arg(char **argv, t_list *head_a)
{
	int		y;
	char	*str;
	t_list	*pile_a;
	int		len;
	char	**split;

	pile_a = head_a;
	split = ft_split(argv[1]);
	len = ft_count_rows(split);
	y = 0;
	while (y < len)
	{
		str = split[y];
		pile_a = ft_parse_one_arg(head_a, pile_a, str);
		if (!pile_a)
			return (ft_free_split(split), NULL);
		if (y < len - 1)
		{
			pile_a->next = ft_mod_new_lst();
			pile_a = pile_a->next;
		}
		y++;
	}
	return (ft_ranking(head_a, pile_a), ft_free_split(split), head_a);
}
