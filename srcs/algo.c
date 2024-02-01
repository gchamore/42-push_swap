/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/01 17:41:13 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	algo_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	compteur;
	
	compteur = 0;
	fill_struct(head_a, nbs);
	ft_algo_pre_tri(head_a, head_b, nbs);
	ft_big_tri(head_a, head_b, nbs);
	// ft_middle_tri(head_a, head_b, nbs);
	// ft_little_tri(head_a, head_b, nbs);
}
void	ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int		check;

	check = nbs->count;
	printf("\n\n&&nb de RANK %d&&\n\n", nbs->count);
	while(*head_a != NULL && check >= 1)
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
	while(*head_a != NULL)
		ft_push_b(head_a, head_b);
}

// tri de la premiere partie de B

void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	t_list	*lst;
	int	temp;
	int search;

	lst = *head_a;
	search = 0;
	temp = 0;
	while(*head_b != NULL && (*head_b)->rank > nbs->div2)
	{
		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
			ft_swap_b(head_b);
		if (*head_a == NULL && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
			ft_push_a(head_b, head_a);
		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
		{
			if (ft_tell_me_positiv(head_a, head_b, nbs) > ft_tell_me_negativ(head_a, head_b, nbs))
			{	
				search = ft_tell_me_negativ(head_a, head_b, nbs) - 1;
				while(search > nbs->div2)
				{
					if (search_position(head_b, search) == 0)
					{
						if (search_position(head_a, search) != 0)
						{
							while(lst != NULL)
							{
								if (lst->rank == search)
								{
									if (which_part(head_a, search) == 3)
										;
									else if (which_part(head_a, search) == 2)
									{
										while ((*head_a)->rank != search)
											ft_reverse_rotate_a(head_a);
									}
									else if (which_part(head_a, search) == 1)
									{
										while((*head_b)->nb_moove != ft_tell_me_negativ(head_a, head_b, nbs) && (*head_a)->rank != search)
										{
											ft_rotate_ab(head_a, head_b);
											temp++;
										}
										while ((*head_a)->rank != search)
											ft_rotate_a(head_a);
										while ((*head_b)->nb_moove != ft_tell_me_negativ(head_a, head_b, nbs))
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
							ft_rotate_a(head_a);
							ft_push_a(head_b, head_a);
							break;
						}
					}
					else if (search_position(head_b, search) != 0)
						search--;
				}
			}
			else
			{
				search = ft_tell_me_positiv(head_a, head_b, nbs) + 1;
				while(search <= nbs->count && search > nbs->div2)
				{
					if (search_position(head_b, search) == 0)
					{
						if (search_position(head_a, search) != 0)
						{
							
							while(lst != NULL)
							{
								if (lst->rank == search)
								{
									if (which_part(head_a, search) == 3)
										break ;
									else if (which_part(head_a, search) == 2)
									{
										while ((*head_a)->rank != search)
											ft_reverse_rotate_a(head_a);
									}
									else if (which_part(head_a, search) == 1)
									{
										while((*head_b)->nb_moove != ft_tell_me_positiv(head_a, head_b, nbs) && (*head_a)->rank != search)
										{
											ft_rotate_ab(head_a, head_b);
											temp++;
										}
										while ((*head_a)->rank != search)
											ft_rotate_a(head_a);
										while ((*head_b)->nb_moove != ft_tell_me_positiv(head_a, head_b, nbs))
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
							break;
						}
					}
					else if (search_position(head_b, search) != 0)
						search++;
				}
			}
		while (temp != 0)
		{
			ft_reverse_rotate_b(head_b);
			temp--;

		}
		}
	}
	
}

// tri de la deuxieme partie de B

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