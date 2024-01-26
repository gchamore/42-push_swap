/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:52 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/26 17:32:15 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	count_rank(t_list	**head)
{
    int		count;
	t_list	*lst;

	lst = *head;
	count = 0;
    while (lst != NULL) 
	{
        count++;
		lst = lst->next;
    }
    return count;
}

void	algo_tri(t_list **head_a, t_list **head_b)
{
	int		count;
	int		check;

	count = count_rank(head_a);
	check = count;
	printf("\n\n&&nb de RANK %d&&\n\n", count);
	printf("\n\nP1 = de %d a %d\nP2 = de %d a %d\nP3 = de %d a %d\n\n", ((count/count)), (count/3), ((count/3 + 1)), (((count/3)*2) + 1), (((count/3)*2) + 2), (count));
	while(*head_a != NULL && check >= 1)
	{
		if (*(*head_a)->rank > (count/3) && (*(*head_a)->rank <= ((count/3)*2)))
			ft_push_b(head_a, head_b);
		else if (*(*head_a)->rank <= (count/3))
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