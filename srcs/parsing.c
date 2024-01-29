/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:49 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/29 17:19:47 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_ranking(t_list *head_a, t_list *pile_a)
{
	t_list	*lst;
	int	rank_count;
	
	pile_a = head_a;
	lst = head_a;
	rank_count = 1;
	while(lst != NULL)
	{
		pile_a = head_a;
		rank_count = 1;
		while(pile_a != NULL)
		{
			if (lst->content > pile_a->content)
				rank_count += 1;
			pile_a = pile_a->next;
		}                                                                                                                                                                                                                                                                                                                                                            
		lst->rank = rank_count;
		lst = lst->next;
	}
}

int int_check_lst(t_list *lst,long int *search)
{
	int		count;
	
	count = 0;
	while(lst != NULL)
	{
		if ((lst->content > 2147483647) || (lst->content < -2147483648))
			return 1;
		if (lst->content == *search)
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

void	*str_check(char *str)
{
	int		i;
	
	i = 0;
	
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
	return (str);
}

void	*ft_parse_one_arg(t_list *head_a, t_list *pile_a, char *str)
{
	char	*temp_str;
	int		len;
	
	if(!str)
		return (NULL);
	len = 0;
	str = str_check(str);
	temp_str = ft_strdup(str_check(str));
	if(!temp_str)
		return (NULL);
	pile_a->content = ft_atol(temp_str);
	free(temp_str);
	if (int_check_lst(head_a,&pile_a->content))
				return (NULL);
	return (pile_a);
}

void	*ft_parse_a(int argc, char **argv, t_list *head_a)
{
	int y;
	char *str;
	t_list	*pile_a;

	y = 1;
	pile_a = head_a;
	while (y < argc)
	{
		str = argv[y];
		pile_a = ft_parse_one_arg(head_a, pile_a, str);
		if(!pile_a)
			return (NULL);
		if (y < argc - 1)
        {
            pile_a->next = ft_new_lst();
			if(!pile_a->next)
				return(NULL);
            pile_a = pile_a->next;
        }
        y++;
	}
	return (ft_ranking(head_a, pile_a), head_a);
}
