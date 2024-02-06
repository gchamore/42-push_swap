/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/06 09:46:41 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
//MENU DE L'ALGO
void	algo_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	compteur;
	
	compteur = 0;
	fill_struct(head_a, nbs);
	ft_algo_pre_tri(head_a, head_b, nbs);
	// ft_big_tri(head_a, head_b, nbs);
	putsmallest_up(head_a);
	// ft_big_tri(head_a, head_b, nbs, compteur);
	// ft_middle_tri(head_a, head_b, nbs);
	// ft_little_tri(head_a, head_b, nbs);
}
//PRE TRI
void	ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int		check;
	int		ct;

	check = nbs->count;
	printf("\n\n&&nb de RANK %d&&\n\n", nbs->count);
	if(check <= 3)
		ft_tri_three_a(head_a);
	while(*head_a != NULL && check >= 1 && nbs->count > 3)
	{			
		if ((*head_a)->rank > nbs->div1 && ((*head_a)->rank <= nbs->div2))
			ft_push_b(head_a, head_b);
		else if ((*head_a)->rank <= nbs->div1)
		{
			ft_push_b(head_a, head_b);
			ft_rotate_b(head_b);
		}
		else
			ft_rotate_a(head_a);
		check--;
	}
	ct = count_lst(head_a);
	while(*head_a != NULL && ct > 3 && nbs->count > 3)
	{
		ft_push_b(head_a, head_b);
		ct--;
	}
	ft_tri_three_a(head_a);
}

void ft_tri_three_a(t_list **head_a)
{
    if (ft_is_sorted(head_a) == 1)
        return ;

    // Trier les trois éléments de la pile A
    if ((*head_a)->rank > (*head_a)->next->rank)
        ft_swap_a(head_a);
    if ((*head_a)->next->rank > (*head_a)->next->next->rank)
    {
        ft_reverse_rotate_a(head_a);
        ft_swap_a(head_a);
    }
	if (ft_is_sorted(head_a) == 1)
        return ;
    if ((*head_a)->rank > (*head_a)->next->rank)
        ft_swap_a(head_a);

    // À ce stade, les trois éléments sont triés.
}

//tri de la premiere partie de B

void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list	*lst;
	t_list	*pos;
	t_list	*neg;
	int	temp;
	int search;
	int	ct;

	lst = *head_a;
	search = 0;
	temp = 0;
	ct = 0;
	while(*head_b != NULL && (*head_b)->rank > nbs->div2)
	{
		pos = ft_tell_me_positiv(head_a, head_b, nbs);
		nbs->best_pos_rank = pos->rank;
		nbs->best_pos_moove = pos->moove;
		neg = ft_tell_me_negativ(head_a, head_b, nbs);
		nbs->best_neg_rank = neg->rank;
		nbs->best_neg_moove = neg->moove;
		if ((nbs->best_neg_moove != 0 && nbs->best_pos_moove == 0) || (nbs->best_pos_moove >= nbs->best_neg_moove && nbs->best_neg_moove != 0))
		{
			lst = *head_a;
			search = nbs->best_neg_rank - 1;
			while(lst != NULL)
			{
				if (lst->rank == search)
				{
					if (which_part(head_a, search) == 2)
					{
						ct = (count_lst(head_a) - search_position(head_a, search));
						while (ct != 0)
						{
							ft_reverse_rotate_a(head_a);
							ct--;
						}
					}
					else if (which_part(head_a, search) == 1)
					{
						while((*head_b)->rank != nbs->best_neg_rank && (*head_a)->rank != search)
						{
							ft_rotate_ab(head_a, head_b);
							temp++;
						}
						while ((*head_a)->rank != search)
							ft_rotate_a(head_a);
						while ((*head_b)->rank != nbs->best_neg_rank)
						{
							ft_rotate_b(head_b);
							temp++;
						}
					}
					break ;
				}
				else
					lst = lst->next;
			}
			ft_push_a(head_b, head_a);
		}
		else if ((nbs->best_neg_moove == 0 && nbs->best_pos_moove != 0) || (nbs->best_pos_moove < nbs->best_neg_moove && nbs->best_pos_moove != 0))
		{
			lst = *head_a;
			search = nbs->best_pos_rank + 1;
			while(lst != NULL)
			{
				if (lst->rank == search)
				{
					if (which_part(head_a, search) == 2)
					{
						while ((*head_a)->rank != search)
							ft_reverse_rotate_a(head_a);
					}
					else if (which_part(head_a, search) == 1)
					{
						while((*head_b)->rank != nbs->best_pos_rank && (*head_a)->rank != search)
						{
							ft_rotate_ab(head_a, head_b);
							temp++;
						}
						while ((*head_a)->rank != search)
							ft_rotate_a(head_a);
						while ((*head_b)->rank != nbs->best_pos_rank)
						{
							ft_rotate_b(head_b);
							temp++;
						}
					}
					break ;
				}
				else
					lst = lst->next;
			}
			ft_push_a(head_b, head_a);
		}
		while (temp != 0)
		{
			ft_reverse_rotate_b(head_b);
			temp--;
		}
	}
}

//tri de la deuxieme partie de B

void	ft_middle_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	temp;
	int search;

	temp = 0;
	search = 0;
	while(*head_b != NULL && (*head_b)->rank <= nbs->div2 && (*head_b)->rank > nbs->div1)
	{
		temp = 0;
		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
			ft_swap_b(head_b);
		if ((*head_a)->rank > nbs->div2 && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
			ft_push_a(head_b, head_a);
		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
		{
			search = (*head_b)->rank + 1;
			while(search <= nbs->count && search <= nbs->div2 && (*head_b)->rank > nbs->div1)
			{
				if (search_position(head_b, search) == 0)
				{
					if (search_position(head_a, search) != 0)
					{
						ft_put_search_first_a(head_a, search);
						ft_push_a(head_b, head_a);
						temp = 1;
						break;
					}
				}
				else if (search_position(head_b, search) != 0)
					search++;
			}
			if (temp == 0)
			{
				search = (*head_b)->rank - 1;
				while(search <= nbs->div2 && (*head_b)->rank > nbs->div1)
				{
					if (search_position(head_b, search) == 0)
					{
						if (search_position(head_a, search) != 0)
						{
							ft_put_search_first_a(head_a, search);
							ft_rotate_a(head_a);
							ft_push_a(head_b, head_a);
							break;
						}
					}
					else if (search_position(head_b, search) != 0)
						search--;
				}
			}
			//check if search -- negativ
		}
	}
	
}

// tri de la troisieme partie de B

void	ft_little_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	temp;
	int search;

	temp = 0;
	search = 0;
	while(*head_b != NULL && (*head_b)->rank <= nbs->div1)
	{
		temp = 0;
		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
			ft_swap_b(head_b);
		if ((*head_a)->rank > nbs->div1 && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
			ft_push_a(head_b, head_a);
		if ((*head_b)->next == NULL && (*head_b)->rank == 1)
		{
			ft_put_search_first_a(head_a, 2);
			ft_push_a(head_b, head_a);
			break;
		}
		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
		{
			search = (*head_b)->rank + 1;
			while(search <= nbs->div1)
			{
				if (search_position(head_b, search) == 0)
				{
					if (search_position(head_a, search) != 0)
					{
						ft_put_search_first_a(head_a, search);
						ft_push_a(head_b, head_a);
						temp = 1;
						break;
					}
				}
				else if (search_position(head_b, search) != 0)
					search++;
			}
			if (temp == 0)
			{
				search = (*head_b)->rank - 1;
				while(search <= nbs->div1)
				{
					if (search_position(head_b, search) == 0)
					{
						if (search_position(head_a, search) != 0)
						{
							ft_put_search_first_a(head_a, search);
							ft_rotate_a(head_a);
							ft_push_a(head_b, head_a);
							break;
						}
					}
					else if (search_position(head_b, search) != 0)
						search--;
				}
			}
			//check if search -- negativ
		}
	}
	
}
