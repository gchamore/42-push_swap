/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:02:31 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 17:02:47 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	free_split(char **split, unsigned int i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return ;
}

static int	count_words(const char *str, char c)
{
	int	count_w;
	int	check;

	count_w = 0;
	check = 0;
	while (*str)
	{
		if (*str != c && check == 0)
		{
			check = 1;
			count_w++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (count_w);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**fill_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		start_or_end;

	i = 0;
	j = 0;
	start_or_end = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_or_end < 0)
			start_or_end = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_or_end >= 0)
		{
			split[j] = word_dup(s, start_or_end, i);
			if (!split[j])
				return (free_split(split, j), NULL);
			start_or_end = -1;
			j++;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split(s, c, split);
	if (!split)
		return (NULL);
	split[count_words(s, c)] = NULL;
	return (split);
}