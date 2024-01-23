/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:11:39 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/17 16:09:46 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>


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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	total;
	int	signe;

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
		total = total * 10 + (str[i] - '0');
		i++;
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

static int	get_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n <= 0)
		num = num * (-1);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (result[digits--] == '0')
		result[digits] = num % 10 + '0';
	while (digits >= 0)
	{
		result[digits] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	if (n <= 0 && n != 0)
		result[0] = '-';
	return (result);
}

int main (int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*head_a;
	int		i;
	char	*str;
	int		temp_int;
	char	*temp_str;
	
	pile_a = NULL;
	head_a = NULL;
	i = 0;
	if (argc > 1)
	{
		head_a = ft_lstnew(NULL);
		pile_a = head_a;
		str = argv[1];
		if (!str)
		return (0);
		while (str[i] && (str[i] < '1' || str[i] > '9'))
			i++;
		while (str[i])
		{
			temp_int = i;
			while (str[i] && str[i] >= '1' && str[i] <= '9')
				i++;
			temp_str = ft_substr(str, temp_int, i + 1);
			if(!temp_str)
				return (0);
			pile_a->content = malloc(sizeof(char) * (ft_strlen(temp_str)));
			if(!pile_a->content)
				return (0);
			*((int *)pile_a->content) = ft_atoi(temp_str);
			while (str[i] && (str[i] < '1' || str[i] > '9'))
				i++;
			if (str[i] != '\0')
			{
				pile_a->next = ft_lstnew(NULL);
				pile_a = pile_a->next;
			}
		}
		pile_a = head_a;
		printf("Liste\n");
		printf("Taille de la liste : %d\n", ft_lstsize(head_a));
		while (pile_a != NULL)
		{
			printf("%d\n", *((int *)pile_a->content));
			pile_a = pile_a->next;
		}
		printf("\n");
		pile_a = head_a;
		while (pile_a != NULL)
		{
			t_list *next = pile_a->next;
			free(pile_a->content);
			free(pile_a);
			pile_a = next;
		}
	}
    return (0);
}
