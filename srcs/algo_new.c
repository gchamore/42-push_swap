/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:44:34 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/06 17:42:33 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_algo_new(t_list **head_a, t_list **head_b, t_nbs *nbs)
{
	fill_struct(head_a, nbs);
	ft_algo_pre_tri(head_a, head_b, nbs);
	while(*head_b != NULL)
	{
		ft_reset_ops(head_b);
		ft_fill_ops(head_a, head_b);
		ft_calcul_ops(head_b);
		ft_exec_ops(head_a, head_b);
	}
}

void	ft_do_ops(t_list **head, t_list **head_a, t_list **head_b)
{
	t_list	*lst;

	lst = *head;
	while (lst->rr > 0)
	{
		ft_rotate_ab(head_a, head_b);
		lst->rr--;
	}
	while (lst->rrr > 0)
	{
		ft_reverse_rotate_ab(head_a, head_b);
		lst->rrr--;
	}
	while (lst->ra > 0)
	{
		ft_rotate_a(head_a);
		lst->ra--;
	}
	while (lst->rb > 0)
	{
		ft_rotate_b(head_b);
		lst->rb--;
	}
	while (lst->rra > 0)
	{
		ft_reverse_rotate_a(head_a);
		lst->rra--;
	}
	while (lst->rrb > 0)
	{
		ft_reverse_rotate_b(head_b);
		lst->rrb--;
	}
	while (lst->pa > 0)
	{
		ft_push_a(head_b, head_a);
		lst->pa--;
	}
}

void	ft_exec_ops(t_list **head_a, t_list **head_b)
{
	t_list	*lst;
	t_list	*save;

	lst = *head_b;
	save = lst;
	while (lst != NULL)
	{
		if (lst->total < save->total)
			save = lst;
		lst = lst->next;
	}
	ft_do_ops(&save, head_a, head_b);
}

int	ft_check_if_small(t_list **head_a, int rank_b)
{
	t_list	*lst;

	lst = *head_a;
	while (lst != NULL)
	{
		if (lst->rank < rank_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_check_if_big(t_list **head_a, int rank_b)
{
	t_list	*lst;

	lst = *head_a;
	while (lst != NULL)
	{
		if (lst->rank > rank_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_reset_ops(t_list **head)
{
	t_list	*lst;
	
	lst = *head;
	while (lst != NULL)
	{
		lst->pa = 1;
		lst->ra = 0;
		lst->rb = 0;
		lst->rr = 0;
		lst->rra = 0;
		lst->rrb = 0;
		lst->rrr = 0;
		lst = lst->next;
	}
}

int		ft_last_rank(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->rank);
}

int	ft_big_a(t_list **head)
{
	t_list	*lst;
	int		save;

	lst = *head;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank > save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}
int	ft_small_a(t_list **head)
{
	t_list	*lst;
	int		save;

	lst = *head;
	save = lst->rank;
	while (lst != NULL)
	{
		if (lst->rank < save)
			save = lst->rank;
		lst = lst->next;
	}
	return (save);
}

t_list	*ft_fill_ops_a(t_list **head_a, t_list *lst1, t_list *lst2)
{
	int	rank;
	int index;
	int middle;
	int	temp;
	
	temp = 1;
	middle = count_lst(head_a)/2;
	while (lst1 != NULL)
	{
		rank = lst1->rank;
		if (ft_check_if_big(head_a, lst2->rank) > 0)
		{
			if (lst1->rank == ft_big_a(head_a))
			{
				lst2->rra++;
				break;
			}
		}
		else if (ft_check_if_small(head_a, lst2->rank) > 0)
		{
			if (lst1->rank == ft_small_a(head_a))
			{
				lst2->rra++;
				break;
			}
		}
		else if (lst1->next != NULL && lst2->rank > rank && lst2->rank < lst1->next->rank)
			break;

		lst1 = lst1->next;
		temp++;
	}
	index = search_position(head_a, lst1->rank);
	if (index > middle)
		lst2->rra = count_lst(head_a) - temp;
	else
		lst2->ra = temp;
	return (lst2);
}

void	ft_fill_ops(t_list **head_a, t_list **head_b)
{
	t_list	*lst1;
	t_list	*lst2;
	int index;
	int middle;
	int	temp;
	
	lst1 = *head_a;
	lst2 = *head_b;
	temp = 1;
	middle = count_lst(head_b)/2;
	
	while (lst2 != NULL)
	{
		lst1 = *head_a;
		if((*head_b)->rank < (*head_a)->rank && (*head_b)->rank > ft_last_rank(head_a))
		{
			ft_push_a(head_b, head_a);
			lst2 = *head_b;
			continue;
		}
		else
			ft_fill_ops_a(head_a, lst1, lst2);
		index = search_position(head_b, lst2->rank);
		if (index > middle)
			lst2->rrb = count_lst(head_b) - temp + 1;
		else
			lst2->rb = index - 1;

		lst2 = lst2->next;
		temp++;
	}
}

void	ft_calcul_ops(t_list **head)
{
	t_list	*lst;

	lst = *head;
	while (lst != NULL)
	{
		while(lst->ra > 0 && lst->rra > 0)
		{
			lst->ra--;
			lst->rra--;
		}
		while(lst->rb > 0 && lst->rrb > 0)
		{
			lst->ra--;
			lst->rra--;
		}
		while(lst->ra > 0 && lst->rb > 0)
		{
			lst->rr++;
			lst->ra--;
			lst->rb--;
		}
		
		while(lst->rra > 0 && lst->rrb > 0)
		{
			lst->rrr++;
			lst->rra--;
			lst->rrb--;
		}
		lst->total = lst->pa + lst->ra + lst->rb + lst->rr + lst->rra + lst->rrb + lst->rrr;
		lst = lst->next;
	}
}

