/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:42:49 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/25 13:16:53 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_ranking(int argc, t_list *head_a, t_list *pile_a)
{
	t_list	*lst;
	int	rank_count;
	int	nb_of_arg_in_lst;
	
	pile_a = head_a;
	lst = head_a;
	rank_count = 0;
	nb_of_arg_in_lst = 0;
	while(lst != NULL)
	{
		pile_a = head_a;
		rank_count = 0;
		while(pile_a != NULL)
		{
			if (*lst->content > *pile_a->content)
				rank_count += 1;
			pile_a = pile_a->next;
		}
		lst->rank = malloc(sizeof(int));                                                                                                                                                                                                                                                                                                                                                                
		*lst->rank = rank_count;
		nb_of_arg_in_lst += 1;
		lst = lst->next;
	}
	printf("nb of arg in lst = %d \nnb of arg = %d\n", nb_of_arg_in_lst, argc);
}

int int_check_lst(t_list *head,long int *search)
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
	
	len = 0;
	str = str_check(str);
	if(!str)
		return (NULL);
	temp_str = ft_strdup(str_check(str));
	if(!temp_str)
		return (NULL);
	pile_a->content = malloc(sizeof(int *));
	if(!pile_a->content)
		return (NULL);
	*pile_a->content = ft_atol(temp_str);
	free(temp_str);
	if (int_check_lst(head_a,pile_a->content))
				return (NULL);
	return (pile_a->content);
}

void	*ft_parse_a(int argc, char **argv, t_list *head_a)
{
	int y;
	char *str;
	t_list	*pile_a;

	y = 1;
	pile_a = head_a;
	// if(argc == 2)
	
	while (y < argc)
	{
		str = argv[y];
		pile_a->content = ft_parse_one_arg(head_a, pile_a, str);
		if(!pile_a->content)
			return (NULL);
		if (y < argc - 1)
        {
            pile_a->next = ft_lstnew(NULL);
            pile_a = pile_a->next;
        }
        y++;
	}
	return (ft_ranking(argc - 1, head_a, pile_a), head_a);
}

// faire le ranking en verifiant pour chaque maillon de la liste combien il y a d'element plus petit (si il y a 5 elements plus petits alors il s'agit du 6eme element de la liste.)