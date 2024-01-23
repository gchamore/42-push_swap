/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:49 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/23 15:02:00 by gchamore         ###   ########.fr       */
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

void free_lst(t_list *lst)
{
	while (lst != NULL)
	{
		t_list *next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
}
int check_lst(t_list *head,long int *search)
{
	t_list	*lst;
	int		count;
	
	lst = head;
	count = 0;
	while(lst != NULL)
	{
		if ((*lst->content > 2147483647) || (*lst->content < -2147483648))
			return 1;
		if (*lst->content == *search)
		{
			count += 1;
			if (count > 1)
				return 1;
		}
		lst = lst->next;
	}
	return 0;
}
void ft_error()
{
	write(1, "Error\n", 6);
}

void	*ft_parse_one_arg(t_list *head_a, t_list *pile_a, char *str)
{
	char	*temp_str;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9')))
			return (NULL);
		//if (+ ou -) devant le nombre
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
		temp_str = ft_strdup(str);
		if(!temp_str)
			return (NULL);
		pile_a->content = malloc(sizeof(int *));
		if(!pile_a->content)
			return (NULL);
		len = ft_strlen(temp_str);
		*pile_a->content = ft_atol(temp_str);
		free(temp_str);
	}
	if (check_lst(head_a,pile_a->content) || len > 11)
				return (NULL);
	return (pile_a->content);
}

int main (int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*head_a;
	char	*str;
	int		y;
	int		len;
	
	y = 1;
	len = 0;
	if (argc > 1)
	{
		head_a = ft_lstnew(NULL);
		pile_a = head_a;
		while (y < argc)
		{
			str = argv[y];
			pile_a->content = ft_parse_one_arg(head_a, pile_a, str);
			if(!pile_a->content)
				return (free_lst(head_a),ft_error(),0);
			
			if (y < argc - 1)
            {
                pile_a->next = ft_lstnew(NULL);
                pile_a = pile_a->next;
            }
            y++;
		}
		pile_a = head_a;
		while (pile_a != NULL)
        {
        	printf("%ld, ", *pile_a->content);
            pile_a = pile_a->next;
        }
		free_lst(head_a);
	}
	return (0);
}
