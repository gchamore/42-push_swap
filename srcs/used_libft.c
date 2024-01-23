/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   used_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/23 14:10:56 by gchamore         ###   ########.fr       */
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

long int	ft_atol(const char *str)
{
	int	i;
	long int	total;
	long int	signe;
	
	total = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = signe * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i++] - '0');
	}
	return (total * signe);
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

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void ft_free_lst(t_list *lst)
{
	while (lst != NULL)
	{
		t_list *next = lst->next;
		free(lst->content);
		free(lst->rank);
		free(lst);
		lst = next;
	}
}
