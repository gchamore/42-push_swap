/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/31 15:04:11 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

// void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur)
// {
// 	int	rotate;
// 	int	found;
// 	int	pass;
	
// 	rotate = nbs->count;
// 	found = 0;
// 	pass = 0;
// 	while((*head_b)->rank > nbs->div2)
// 	{
// 		if ((*head_b)->rank != rotate || (*head_b)->rank != (rotate - 1))
// 		{
// 			if ((*head_b)->rank < (*head_b)->next->rank)
// 				ft_swap_b(head_b);
// 			else
// 			{
// 				ft_rotate_b(head_b);
// 				compteur++;
// 			}
// 		}
// 		else 
// 		{
// 			if((*head_b)->rank == rotate && found != 1)
// 			{
// 				ft_push_a(head_b, head_a);
// 				rotate--;
// 				found = 1;
// 				pass += 1;
// 			}
// 			else if ((*head_b)->rank == (rotate - 1) && found != -1)
// 			{	
// 				ft_push_a(head_b, head_a);
// 				rotate--;
// 				if ((*head_a)->next != NULL && (*head_a)->rank > (*head_a)->next->rank) 
// 					ft_swap_a(head_a);
// 				found = -1;
// 				pass +=1;
// 			}
// 			while(pass == 2 && compteur != 0)
// 			{
// 				ft_reverse_rotate_b(head_b);
// 				compteur--;
// 			}
// 		}
// 		found = 0;
// 		pass = 0;
// 	}
// }

// void	ft_middle_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur)
// {
// 	int	rotate;
	
// 	rotate = nbs->count - (nbs->count - nbs->div2);
// 	while((*head_b)->rank <= nbs->div2 && (*head_b)->rank > nbs->div1)
// 	{
// 		if ((*head_b)->rank != rotate)
// 		{
// 			ft_rotate_b(head_b);
// 			compteur++;
// 		}
// 		else if((*head_b)->rank == rotate)
// 		{
// 			ft_push_a(head_b, head_a);
// 			rotate--;
// 			while(compteur != 0)
// 			{
// 				ft_reverse_rotate_b(head_b);
// 				compteur--;
// 			}
// 		}
// 	}
// }

// void	ft_little_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur)
// {
// 	int	rotate;
	
// 	rotate = (nbs->count - (nbs->count - nbs->div2)) - nbs->div1;
// 	while(*head_b != NULL && (*head_b)->rank <= nbs->div1)
// 	{
// 		if ((*head_b)->rank != rotate)
// 		{
// 			ft_rotate_b(head_b);
// 			compteur++;
// 		}
// 		else if((*head_b)->rank == rotate)
// 		{
// 			ft_push_a(head_b, head_a);
// 			rotate--;
// 			while(compteur != 0)
// 			{
// 				ft_reverse_rotate_b(head_b);
// 				compteur--;
// 			}
// 		}
// 	}
// }

void	algo_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	int	compteur;
	
	compteur = 0;
	ft_algo_pre_tri(head_a, head_b, nbs);
	ft_big_tri(head_a, head_b, nbs);
	// ft_middle_tri(head_a, head_b, nbs, compteur);
	// ft_little_tri(head_a, head_b, nbs, compteur);
	// quick_sort_big(head_a, head_b, nbs);
}


// t_list *temp;
	
// 	while ((*head_b)->rank > nbs->div2)
// 	{
// 		if ((*head_b)->rank < (*head_b)->next->rank)
// 			ft_swap_b(head_b);
// 		ft_push_a(head_b, head_a);
// 		temp = *head_a;
// 		ft_lstlast(&temp);
// 		if ((*head_a)->next != NULL && (*head_a)->rank > (*head_a)->next->rank) 
// 		{
// 			if ((*head_a)->next->next != NULL && (*head_a)->rank > (*head_a)->next->next->rank)
// 			{
// 				if(temp->rank > (*head_a)->rank)
// 				{
// 					ft_reverse_rotate_a(head_a);
// 					ft_swap_a(head_a);
// 					ft_rotate_a(head_a);
// 				}
// 				ft_rotate_a(head_a);
// 			}
// 			else
// 				ft_swap_a(head_a);
// 		}
		
// 		ft_big_check(head_a, head_b, nbs);
// 	}