// void ft_tri_three_a(t_list **head_a)
// {
// 	if ((*head_a)->rank > (*head_a)->next->rank && (*head_a)->rank > (*head_a)->next->next->rank)
// 	{
// 		ft_rotate_a(head_a);
// 		if ((*head_a)->rank > (*head_a)->next->rank)
// 			ft_swap_a(head_a);
// 	}
// 	if ((*head_a)->rank > (*head_a)->next->rank && (*head_a)->rank < (*head_a)->next->next->rank)
// 		ft_swap_a(head_a);
	
// }


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