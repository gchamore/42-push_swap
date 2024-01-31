/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:57:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/31 15:47:43 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// void	recursif_quick(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
	
// }

int	count_lst(t_list **head)
{
	t_list	*lst;
	int count;

	lst = *head;
	count = 0;
    while (lst != NULL) 
	{
        count++;
		lst = lst->next;
    }
	return (count);
}

int	which_part(t_list **head, int search)
{
	int	med;
	int total;
	t_list	*lst;
	
	lst = *head;
	total = count_lst(head);
	if (total == 1)
		return 3;
	med = total/2;
	while(lst != NULL && total > med)
	{
		if(search == lst->rank)
			return 1;
		else
			lst = lst->next;
		total--;
	}
	while(lst != NULL && total <= med)
	{
		if(search == lst->rank)
			return 2;
		else
			lst = lst->next;
		total--;
	}
	return 0;
}
int	search_position(t_list **head, int search)
{
	int	ct;
	t_list	*lst;
	
	lst = *head;
	ct = 1;
	while(lst != NULL)
	{
		if(lst->rank == search)
			return (ct);
		else
			lst = lst->next;
		ct++;
	}
	return (0);
}

void	ft_put_search_first_a(t_list **head_a, int search)
{
	t_list	*lst;
	
	lst = *head_a;
	while(lst != NULL)
	{
		if (lst->rank == search)
		{
			if (which_part(head_a, search) == 3)
				return ;
			else if (which_part(head_a, search) == 1)
			{
				while ((*head_a)->rank != search)
					ft_reverse_rotate_a(head_a);
			}
			else if (which_part(head_a, search) == 2)
			{
				while ((*head_a)->rank != search)
					ft_rotate_a(head_a);
			}
		}
		else
			lst = lst->next;
	}
}

void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	temp;
	int search;

	temp = 0;
	search = 0;
	while(*head_b != NULL && (*head_b)->rank > nbs->div2)
	{
		// if (*head_a && (*head_a)->next && (*head_b)->next && ((*head_b)->rank\
		//  < (*head_b)->next->rank) && ((*head_a)->rank > (*head_a)->next->rank))
		// 	ft_swap_ab(head_a, head_b);s
		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
			ft_swap_b(head_b);
		if (*head_a == NULL && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
			ft_push_a(head_b, head_a);
		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
		{
			search = (*head_b)->rank + 1;
			while(search <= nbs->count && search > nbs->div2)
			{
				if (search_position(head_b, search) == 0)
				{
					if (search_position(head_a, search) != 0)
					{
						ft_put_search_first_a(head_a, search);
						ft_push_a(head_b, head_a);
					}
				}
				else if (search_position(head_b, search) != 0)
					search++;
			}
			search = (*head_b)->rank - 1;
			while(search > nbs->div2)
			{
				if (search_position(head_b, search) == 0)
				{
					if (search_position(head_a, search) != 0)
					{
						ft_put_search_first_a(head_a, search);
						ft_rotate_a(head_a);
						ft_push_a(head_b, head_a);
					}
				}
				else if (search_position(head_b, search) != 0)
					search--;
			}
			//check if search -- negativ
		}
	}
	
}

void	ft_middle_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur)
{
	int	rotate;
	
	rotate = nbs->count - (nbs->count - nbs->div2);
	while((*head_b)->rank <= nbs->div2 && (*head_b)->rank > nbs->div1)
	{
		if ((*head_b)->rank != rotate)
		{
			ft_rotate_b(head_b);
			compteur++;
		}
		else if((*head_b)->rank == rotate)
		{
			ft_push_a(head_b, head_a);
			rotate--;
			while(compteur != 0)
			{
				ft_reverse_rotate_b(head_b);
				compteur--;
			}
		}
	}
}

void	ft_little_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur)
{
	int	rotate;
	
	rotate = (nbs->count - (nbs->count - nbs->div2)) - nbs->div1;
	while(*head_b != NULL && (*head_b)->rank <= nbs->div1)
	{
		if ((*head_b)->rank != rotate)
		{
			ft_rotate_b(head_b);
			compteur++;
		}
		else if((*head_b)->rank == rotate)
		{
			ft_push_a(head_b, head_a);
			rotate--;
			while(compteur != 0)
			{
				ft_reverse_rotate_b(head_b);
				compteur--;
			}
		}
	}
}
























// void	quick_sort_big(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	int med;
// 	int	rotate;
// 	int	save;
// 	int	save_ct;

// 	rotate = 0;
// 	save = 0;
// 	save_ct = 0;
// 	med = (*head_b)->rank;
// 	ft_printf("\n\nmed = %d\n", med);
// 	ft_rotate_b(head_b);
// 	while((*head_b)->rank > nbs->div2)
// 	{
// 		if ((*head_b)->rank < med)
// 		{
// 			if(rotate != 0)
// 			{
// 				ft_reverse_rotate_b(head_b);
// 				ft_swap_b(head_b);
// 				ft_rotate_b(head_b);
// 				ft_rotate_b(head_b);
// 				rotate += 1;
// 			}
// 			if(rotate == 0)
// 			{
// 				ft_rotate_b(head_b);
// 				rotate += 1;
// 			}
// 		}
// 		if ((*head_b)->rank > med)
// 		{
// 			if (save_ct == 0)
// 			{
// 				save = (*head_b)->rank;
// 				save_ct += 1;
// 			}
// 			if (save < (*head_b)->rank && save_ct == 1)
// 				save = (*head_b)->rank;
// 			ft_rotate_b(head_b);
// 			rotate += 1;
// 		}
// 		if ((*head_b)->rank == med)
// 		{
// 			ft_push_a(head_b, head_a);
// 			quick_sort_big(head_a, head_b, nbs);
// 		}
// 	}
// 	while(rotate > 0)
// 	{
// 		ft_reverse_rotate_b(head_b);
// 		if ((*head_b)->rank == save_ct)
// 			ft_reverse_rotate_a(head_a);
// 		ft_push_a(head_b, head_a);
// 		rotate--;
// 	}
// 	}
// }