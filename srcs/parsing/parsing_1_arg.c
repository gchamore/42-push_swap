/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:57:19 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/07 18:57:35 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

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

void	*verif_str(char **split, char *str, int i)
{
	int	row;
	int	collum;

	row = 0;
	while (str[i])
	{
		collum = 0;
		split[row] = (char *)malloc(sizeof(char) * 4096);
		if (!split[row])
			return (NULL);
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			split[row][collum] = str[i];
			i++;
			collum++;
		}
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		split[row][collum] = '\0';
		row++;
	}
	split[row] = NULL;
	return (split);
}

char	**ft_split(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	split = verif_str(split, str, i);
	if (!split)
		return (free(split), NULL);
	return (split);
}

void	*ft_parse_1_arg(char **argv, t_list *head_a)
{
	int		y;
	char	*str;
	t_list	*pile_a;
	int		len;
	char	**split;

	y = 1;
	pile_a = head_a;
	split = ft_split(argv[1]);
	len = ft_count_rows(split);
	y = 0;
	while (y < len)
	{	
		str = split[y];
		pile_a = ft_parse_one_arg(head_a, pile_a, str);
		if (!pile_a)
			return (NULL);
		if (y < len - 1)
		{
			pile_a->next = ft_mod_new_lst();
			pile_a = pile_a->next;
		}
		y++;
	}
	return (ft_ranking(head_a, pile_a), free_split(split), head_a);
}
