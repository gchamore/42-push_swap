/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/06 14:52:43 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str1)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst)
	{
		while (lst != NULL)
		{
			size++;
			lst = lst -> next;
		}
		return (size);
	}
	return (0);
}
