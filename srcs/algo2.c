/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:52:50 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/01 17:38:32 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//Attribue a chaque maillont de la liste B une valeur nb_moove qui 
//correspont au nombre de moove fait.
int	ft_best_pos(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst;
	int best_pos;

	lst = *head_b;
	best_pos = 0;
	while (lst->rank != ft_tell_me_positiv(head_a, head_b, nbs))
		lst = lst->next;
	best_pos = lst->nb_moove;
	return (lst->nb_moove);
}

int	ft_best_neg(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst;
	int best_neg;

	lst = *head_b;
	best_neg = 0;
	while (lst->rank != ft_tell_me_negativ(head_a, head_b, nbs))
		lst = lst->next;
	best_neg = lst->nb_moove;
	return (lst->nb_moove);
}
int	check_best_option(t_list **head_b)
{
	t_list *lst;
	int		save;

	lst = *head_b;
	save = lst->nb_moove;
	while (lst != NULL)
	{
		if(lst->nb_moove < save)
			save = lst->nb_moove;
		lst = lst->next;
	}
	return (save);
}

int ft_tell_me_positiv(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst1;
	t_list *lst2;
	int	temp;
	int search;

	lst1 = *head_a;
	lst2 = *head_b;
	temp = 0;
	while (lst2 != NULL && lst2->rank > nbs->div2)
	{
		search = lst2->rank;
		while(search <= nbs->count && search > nbs->div2)
		{
			search++;
			if (search_position(head_b, search) == 0)
			{
				if (search_position(head_a, search) != 0)
				{
					while(lst1 != NULL)
					{
						if (lst1->rank == search)
						{
							if (which_part(head_a, search) == 3)
								return (0);
							if (which_part(head_a, search) == 2)
							{
								while ((*head_a)->rank != search)
									lst2->nb_moove += 1;//ft_reverse_rotate_a(head_a);
							}
							else if (which_part(head_a, search) == 1)
							{
								while ((*head_a)->rank != search)
									lst2->nb_moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
							}
							break;
						}
						else
							lst1 = lst1->next;
					}
					lst2->nb_moove += 1; //(push)
					break;
				}
			}
			else if (search_position(head_b, search) != 0)
				search++;
		}
		lst2 = lst2->next;
		lst2->nb_moove += 2;
	}
	return(check_best_option(head_b));
}

int ft_tell_me_negativ(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst1;
	t_list *lst2;
	int	temp;
	int search;

	lst1 = *head_a;
	lst2 = *head_b;
	temp = 0;
	while (lst2 != NULL && lst2->rank > nbs->div2)
	{
		search = lst2->rank;
		while(search <= nbs->count && search > nbs->div2)
		{
			search--;
			if (search_position(head_b, search) == 0)
			{
				if (search_position(head_a, search) != 0)
				{
					while(lst1 != NULL)
					{
						if (lst1->rank == search)
						{
							if (which_part(head_a, search) == 3)
								return (0);
							if (which_part(head_a, search) == 2)
							{
								while ((*head_a)->rank != search)
									lst2->nb_moove += 1;//(ft_reverse_rotate_a(head_a));
							}
							else if (which_part(head_a, search) == 1)
							{
								while ((*head_a)->rank != search)
									lst2->nb_moove += 1;//(ft_rotate_a(head_a))
							}
							break;
						}
						else
							lst1 = lst1->next;
					}
					lst2->nb_moove += 1; //ft_rotate_a(head_a) + (ft_push_a(head_b, head_a));
					break;
				}
			}
			else if (search_position(head_b, search) != 0)
				search++;
		}
		lst2 = lst2->next;
		lst2->nb_moove += 2;//(ft_rotate_b(head_b); + reverse rotate pour remettre comme avant)
	}
	return(check_best_option(head_b));
}
