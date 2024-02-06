/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:52:50 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/05 17:34:58 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_is_smallest(t_list **head_a)
{
	t_list	*lst;
	int		save;

	lst = *head_a;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank < save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}

int	check_if_biggest(t_list **head_a, int rank_b)
{
	t_list	*lst;
	int	ct;

	lst = *head_a;
	ct = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank > rank_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}
//Met le rank le plus petit en haut de la pile.
void	putsmallest_up(t_list **head)
{
	t_list	*lst;
	int	ct;

	lst = *head;
	ct = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank < ct)
			ct = lst->rank;
		lst = lst->next;
	}
	while ((*head)->rank != ct)
	{
		if (which_part(head, ct) == 2)
		{
			ft_reverse_rotate_a(head);
		}
		else if (which_part(head, ct) == 1)
		{
			ft_rotate_a(head);
		}
	}
}

//check le meilleur rank entre positif et negatif pour envoyer la head de b dans a.
t_list	*check_best_option(t_list **head_b, t_nbs *nbs)
{
	t_list *lst;
	t_list  *save;

	lst = *head_b;
	save = lst;
	while (lst != NULL && lst->rank > nbs->div2)
	{
		if((save->moove == 0) || (lst->moove < save->moove && lst->moove != 0))
			save = lst;
		lst = lst->next;
	}
	return (save);
}
//clear les mooves effectue entre le test sur positif et negatif
void	ft_clear_nb_moove(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst != NULL)
	{
		lst->moove = 0;
		lst = lst->next;
	}
}

//retourne par le biais de check_best_option le meilleur positif au dessus 
//de head de B a aller chercher dans A en terme de nb de coups.
t_list *ft_tell_me_positiv(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst1;
	t_list *lst2;
	int	temp;
	int	temp2;
	int search;

	ft_clear_nb_moove(head_b);
	lst1 = *head_a;
	lst2 = *head_b;
	temp = 0;
	temp2 = 0;
	while (lst2 != NULL && lst2->rank > nbs->div2)
	{
		lst1 = *head_a;
		search = lst2->rank + 1;
		while(search <= nbs->count && search > nbs->div2)
		{
			if (search_position(head_b, search) == 0)
			{
				if (search_position(head_a, search) != 0)
				{
					while(lst1 != NULL)
					{
						if (lst1->rank == search)
						{
							if (which_part(head_a, search) == 2)
							{
								lst1 = *head_a;
								temp2 = (count_lst(&lst1) - search_position(&lst1, search) + 1);
								while(temp2 != 0)
								{
									lst2->moove += 1;
									temp2--;
								}
							}
							else if (which_part(head_a, search) == 1)
							{
								lst1 = *head_a;
								while (lst1->rank != search)
								{
									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
									lst1 = lst1->next;
								}
								temp2 = temp;
								while(lst2->moove != (lst2->moove - temp2))
								{
									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
									temp2--;
								}
							}
							break;
						}
						else
							lst1 = lst1->next;
					}
					lst2->moove += 1; //(push)
					break;
				}
			}
			else if (search_position(head_b, search) != 0)
				search++;
		}
		lst2 = lst2->next;
		if(lst2 != NULL && lst2->rank > nbs->div2)
		{
			lst2->moove += (1 + temp);
			temp += 1;
		}
	}
	return(check_best_option(head_b, nbs));
}

//retourne par le biais de check_best_option le meilleur negatif en dessous
//de head de B a aller chercher dans A en terme de nb de coups.
t_list *ft_tell_me_negativ(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list *lst1;
	t_list *lst2;
	int	temp;
	int search;
	int	temp2;

	ft_clear_nb_moove(head_b);
	lst1 = *head_a;
	lst2 = *head_b;
	temp = 0;
	temp2 = 0;
	while (lst2 != NULL && lst2->rank > nbs->div2)
	{
		lst1 = *head_a;
		search = lst2->rank - 1;
		while(search <= nbs->count && search > nbs->div2)
		{
			if (search_position(head_b, search) == 0)
			{
				if (search_position(head_a, search) != 0)
				{
					while(lst1 != NULL)
					{
						if (lst1->rank == search)
						{
							if (which_part(head_a, search) == 2)
							{
								lst1 = *head_a;
								temp2 = (count_lst(&lst1) - search_position(&lst1, search));
								while(temp2 != 0)
								{
									lst2->moove += 1;
									temp2--;
								}
							}
							else if (which_part(head_a, search) == 1)
							{
								lst1 = *head_a;
								while (lst1->rank != search)
								{
									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
									lst1 = lst1->next;
								}
								temp2 = temp;
								while(lst2->moove != (lst2->moove - temp2))
								{
									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
									temp2--;
								}
							}
							break;
						}
						else
							lst1 = lst1->next;
					}
					lst2->moove += 1; //(ft_push_a(head_b, head_a) + ft_swap_a(head_a));
					break;
				}
			}
			else if (search_position(head_b, search) != 0)
				search--;
		}
		lst2 = lst2->next;
		if(lst2 != NULL && lst2->rank > nbs->div2)
		{
			lst2->moove += (1 + temp);//(ft_rotate_b(head_b); + reverse rotate pour remettre comme avant)
			temp += 1;
		}
	}
	return(check_best_option(head_b, nbs));
}
