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

//MENU DE L'ALGO
// void	algo_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	int	compteur;
	
// 	compteur = 0;
// 	fill_struct(head_a, nbs);
// 	ft_algo_pre_tri(head_a, head_b, nbs);
// 	ft_big_tri(head_a, head_b, nbs);
// 	putsmallest_up(head_a);
// 	ft_big_tri(head_a, head_b, nbs, compteur);
// 	ft_middle_tri(head_a, head_b, nbs);
// 	ft_little_tri(head_a, head_b, nbs);
// }
//PRE TRI
// void	ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	int		check;
// 	int		ct;

// 	check = nbs->count;
// 	printf("\n\n&&nb de RANK %d&&\n\n", nbs->count);
// 	if(check <= 3)
// 		ft_tri_three_a(head_a);
// 	while(*head_a != NULL && check >= 1 && nbs->count > 3)
// 	{			
// 		if ((*head_a)->rank > nbs->div1 && ((*head_a)->rank <= nbs->div2))
// 			ft_push_b(head_a, head_b);
// 		else if ((*head_a)->rank <= nbs->div1)
// 		{
// 			ft_push_b(head_a, head_b);
// 			ft_rotate_b(head_b);
// 		}
// 		else
// 			ft_rotate_a(head_a);
// 		check--;
// 	}
// 	ct = count_lst(head_a);
// 	while(*head_a != NULL && ct > 3 && nbs->count > 3)
// 	{
// 		ft_push_b(head_a, head_b);
// 		ct--;
// 	}
// 	ft_tri_three_a(head_a);
// }

// void ft_tri_three_a(t_list **head_a)
// {
//     if (ft_is_sorted(head_a) == 1)
//         return ;

//     // Trier les trois éléments de la pile A
//     if ((*head_a)->rank > (*head_a)->next->rank)
//         ft_swap_a(head_a);
//     if ((*head_a)->next->rank > (*head_a)->next->next->rank)
//     {
//         ft_reverse_rotate_a(head_a);
//         ft_swap_a(head_a);
//     }
// 	if (ft_is_sorted(head_a) == 1)
//         return ;
//     if ((*head_a)->rank > (*head_a)->next->rank)
//         ft_swap_a(head_a);

//     // À ce stade, les trois éléments sont triés.
// }

// //tri de la premiere partie de B

// void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	t_list	*lst;
// 	t_list	*pos;
// 	t_list	*neg;
// 	int	temp;
// 	int search;
// 	int	ct;

// 	lst = *head_a;
// 	search = 0;
// 	temp = 0;
// 	ct = 0;
// 	while(*head_b != NULL && (*head_b)->rank > nbs->div2)
// 	{
// 		pos = ft_tell_me_positiv(head_a, head_b, nbs);
// 		nbs->best_pos_rank = pos->rank;
// 		nbs->best_pos_moove = pos->moove;
// 		neg = ft_tell_me_negativ(head_a, head_b, nbs);
// 		nbs->best_neg_rank = neg->rank;
// 		nbs->best_neg_moove = neg->moove;
// 		if ((nbs->best_neg_moove != 0 && nbs->best_pos_moove == 0) || (nbs->best_pos_moove >= nbs->best_neg_moove && nbs->best_neg_moove != 0))
// 		{
// 			lst = *head_a;
// 			search = nbs->best_neg_rank - 1;
// 			while(lst != NULL)
// 			{
// 				if (lst->rank == search)
// 				{
// 					if (which_part(head_a, search) == 2)
// 					{
// 						ct = (count_lst(head_a) - search_position(head_a, search));
// 						while (ct != 0)
// 						{
// 							ft_reverse_rotate_a(head_a);
// 							ct--;
// 						}
// 					}
// 					else if (which_part(head_a, search) == 1)
// 					{
// 						while((*head_b)->rank != nbs->best_neg_rank && (*head_a)->rank != search)
// 						{
// 							ft_rotate_ab(head_a, head_b);
// 							temp++;
// 						}
// 						while ((*head_a)->rank != search)
// 							ft_rotate_a(head_a);
// 						while ((*head_b)->rank != nbs->best_neg_rank)
// 						{
// 							ft_rotate_b(head_b);
// 							temp++;
// 						}
// 					}
// 					break ;
// 				}
// 				else
// 					lst = lst->next;
// 			}
// 			ft_push_a(head_b, head_a);
// 		}
// 		else if ((nbs->best_neg_moove == 0 && nbs->best_pos_moove != 0) || (nbs->best_pos_moove < nbs->best_neg_moove && nbs->best_pos_moove != 0))
// 		{
// 			lst = *head_a;
// 			search = nbs->best_pos_rank + 1;
// 			while(lst != NULL)
// 			{
// 				if (lst->rank == search)
// 				{
// 					if (which_part(head_a, search) == 2)
// 					{
// 						while ((*head_a)->rank != search)
// 							ft_reverse_rotate_a(head_a);
// 					}
// 					else if (which_part(head_a, search) == 1)
// 					{
// 						while((*head_b)->rank != nbs->best_pos_rank && (*head_a)->rank != search)
// 						{
// 							ft_rotate_ab(head_a, head_b);
// 							temp++;
// 						}
// 						while ((*head_a)->rank != search)
// 							ft_rotate_a(head_a);
// 						while ((*head_b)->rank != nbs->best_pos_rank)
// 						{
// 							ft_rotate_b(head_b);
// 							temp++;
// 						}
// 					}
// 					break ;
// 				}
// 				else
// 					lst = lst->next;
// 			}
// 			ft_push_a(head_b, head_a);
// 		}
// 		while (temp != 0)
// 		{
// 			ft_reverse_rotate_b(head_b);
// 			temp--;
// 		}
// 	}
// }

// //tri de la deuxieme partie de B

// void	ft_middle_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	int	temp;
// 	int search;

// 	temp = 0;
// 	search = 0;
// 	while(*head_b != NULL && (*head_b)->rank <= nbs->div2 && (*head_b)->rank > nbs->div1)
// 	{
// 		temp = 0;
// 		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
// 			ft_swap_b(head_b);
// 		if ((*head_a)->rank > nbs->div2 && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
// 			ft_push_a(head_b, head_a);
// 		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
// 		{
// 			search = (*head_b)->rank + 1;
// 			while(search <= nbs->count && search <= nbs->div2 && (*head_b)->rank > nbs->div1)
// 			{
// 				if (search_position(head_b, search) == 0)
// 				{
// 					if (search_position(head_a, search) != 0)
// 					{
// 						ft_put_search_first_a(head_a, search);
// 						ft_push_a(head_b, head_a);
// 						temp = 1;
// 						break;
// 					}
// 				}
// 				else if (search_position(head_b, search) != 0)
// 					search++;
// 			}
// 			if (temp == 0)
// 			{
// 				search = (*head_b)->rank - 1;
// 				while(search <= nbs->div2 && (*head_b)->rank > nbs->div1)
// 				{
// 					if (search_position(head_b, search) == 0)
// 					{
// 						if (search_position(head_a, search) != 0)
// 						{
// 							ft_put_search_first_a(head_a, search);
// 							ft_rotate_a(head_a);
// 							ft_push_a(head_b, head_a);
// 							break;
// 						}
// 					}
// 					else if (search_position(head_b, search) != 0)
// 						search--;
// 				}
// 			}
// 			//check if search -- negativ
// 		}
// 	}
	
// }

// // tri de la troisieme partie de B

// void	ft_little_tri(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	int	temp;
// 	int search;

// 	temp = 0;
// 	search = 0;
// 	while(*head_b != NULL && (*head_b)->rank <= nbs->div1)
// 	{
// 		temp = 0;
// 		if ((*head_b)->next && (*head_b)->rank < (*head_b)->next->rank)
// 			ft_swap_b(head_b);
// 		if ((*head_a)->rank > nbs->div1 && (*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
// 			ft_push_a(head_b, head_a);
// 		if ((*head_b)->next == NULL && (*head_b)->rank == 1)
// 		{
// 			ft_put_search_first_a(head_a, 2);
// 			ft_push_a(head_b, head_a);
// 			break;
// 		}
// 		else if ((*head_b)->next && (*head_b)->rank > (*head_b)->next->rank)
// 		{
// 			search = (*head_b)->rank + 1;
// 			while(search <= nbs->div1)
// 			{
// 				if (search_position(head_b, search) == 0)
// 				{
// 					if (search_position(head_a, search) != 0)
// 					{
// 						ft_put_search_first_a(head_a, search);
// 						ft_push_a(head_b, head_a);
// 						temp = 1;
// 						break;
// 					}
// 				}
// 				else if (search_position(head_b, search) != 0)
// 					search++;
// 			}
// 			if (temp == 0)
// 			{
// 				search = (*head_b)->rank - 1;
// 				while(search <= nbs->div1)
// 				{
// 					if (search_position(head_b, search) == 0)
// 					{
// 						if (search_position(head_a, search) != 0)
// 						{
// 							ft_put_search_first_a(head_a, search);
// 							ft_rotate_a(head_a);
// 							ft_push_a(head_b, head_a);
// 							break;
// 						}
// 					}
// 					else if (search_position(head_b, search) != 0)
// 						search--;
// 				}
// 			}
// 			//check if search -- negativ
// 		}
// 	}
	
// }


// int	check_is_smallest(t_list **head_a)
// {
// 	t_list	*lst;
// 	int		save;

// 	lst = *head_a;
// 	save = lst->rank;
// 	while (lst != NULL)
// 	{
// 		if (lst->rank < save)
// 			save = lst->rank;
// 		lst = lst->next;
// 	}
// 	return (save);
// }

// int	check_if_biggest(t_list **head_a, int rank_b)
// {
// 	t_list	*lst;
// 	int	ct;

// 	lst = *head_a;
// 	ct = lst->rank;
// 	while (lst != NULL)
// 	{
// 		if (lst->rank > rank_b)
// 			return (0);
// 		lst = lst->next;
// 	}
// 	return (1);
// }
// //Met le rank le plus petit en haut de la pile.

// //check le meilleur rank entre positif et negatif pour envoyer la head de b dans a.
// t_list	*check_best_option(t_list **head_b, t_nbs *nbs)
// {
// 	t_list *lst;
// 	t_list  *save;

// 	lst = *head_b;
// 	save = lst;
// 	while (lst != NULL && lst->rank > nbs->div2)
// 	{
// 		if((save->moove == 0) || (lst->moove < save->moove && lst->moove != 0))
// 			save = lst;
// 		lst = lst->next;
// 	}
// 	return (save);
// }
// //clear les mooves effectue entre le test sur positif et negatif
// void	ft_clear_nb_moove(t_list **head)
// {
// 	t_list	*lst;

// 	lst = *head;
// 	while (lst != NULL)
// 	{
// 		lst->moove = 0;
// 		lst = lst->next;
// 	}
// }

// //retourne par le biais de check_best_option le meilleur positif au dessus 
// //de head de B a aller chercher dans A en terme de nb de coups.
// t_list *ft_tell_me_positiv(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	t_list *lst1;
// 	t_list *lst2;
// 	int	temp;
// 	int	temp2;
// 	int search;

// 	ft_clear_nb_moove(head_b);
// 	lst1 = *head_a;
// 	lst2 = *head_b;
// 	temp = 0;
// 	temp2 = 0;
// 	while (lst2 != NULL && lst2->rank > nbs->div2)
// 	{
// 		lst1 = *head_a;
// 		search = lst2->rank + 1;
// 		while(search <= nbs->count && search > nbs->div2)
// 		{
// 			if (search_position(head_b, search) == 0)
// 			{
// 				if (search_position(head_a, search) != 0)
// 				{
// 					while(lst1 != NULL)
// 					{
// 						if (lst1->rank == search)
// 						{
// 							if (which_part(head_a, search) == 2)
// 							{
// 								lst1 = *head_a;
// 								temp2 = (count_lst(&lst1) - search_position(&lst1, search) + 1);
// 								while(temp2 != 0)
// 								{
// 									lst2->moove += 1;
// 									temp2--;
// 								}
// 							}
// 							else if (which_part(head_a, search) == 1)
// 							{
// 								lst1 = *head_a;
// 								while (lst1->rank != search)
// 								{
// 									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
// 									lst1 = lst1->next;
// 								}
// 								temp2 = temp;
// 								while(lst2->moove != (lst2->moove - temp2))
// 								{
// 									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
// 									temp2--;
// 								}
// 							}
// 							break;
// 						}
// 						else
// 							lst1 = lst1->next;
// 					}
// 					lst2->moove += 1; //(push)
// 					break;
// 				}
// 			}
// 			else if (search_position(head_b, search) != 0)
// 				search++;
// 		}
// 		lst2 = lst2->next;
// 		if(lst2 != NULL && lst2->rank > nbs->div2)
// 		{
// 			lst2->moove += (1 + temp);
// 			temp += 1;
// 		}
// 	}
// 	return(check_best_option(head_b, nbs));
// }

// //retourne par le biais de check_best_option le meilleur negatif en dessous
// //de head de B a aller chercher dans A en terme de nb de coups.
// t_list *ft_tell_me_negativ(t_list **head_a, t_list **head_b, t_nbs *nbs)
// {
// 	t_list *lst1;
// 	t_list *lst2;
// 	int	temp;
// 	int search;
// 	int	temp2;

// 	ft_clear_nb_moove(head_b);
// 	lst1 = *head_a;
// 	lst2 = *head_b;
// 	temp = 0;
// 	temp2 = 0;
// 	while (lst2 != NULL && lst2->rank > nbs->div2)
// 	{
// 		lst1 = *head_a;
// 		search = lst2->rank - 1;
// 		while(search <= nbs->count && search > nbs->div2)
// 		{
// 			if (search_position(head_b, search) == 0)
// 			{
// 				if (search_position(head_a, search) != 0)
// 				{
// 					while(lst1 != NULL)
// 					{
// 						if (lst1->rank == search)
// 						{
// 							if (which_part(head_a, search) == 2)
// 							{
// 								lst1 = *head_a;
// 								temp2 = (count_lst(&lst1) - search_position(&lst1, search));
// 								while(temp2 != 0)
// 								{
// 									lst2->moove += 1;
// 									temp2--;
// 								}
// 							}
// 							else if (which_part(head_a, search) == 1)
// 							{
// 								lst1 = *head_a;
// 								while (lst1->rank != search)
// 								{
// 									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
// 									lst1 = lst1->next;
// 								}
// 								temp2 = temp;
// 								while(lst2->moove != (lst2->moove - temp2))
// 								{
// 									lst2->moove += 1;//(ft_rotate_a(head_a)) ou (ft_rotate_ab(head_a))
// 									temp2--;
// 								}
// 							}
// 							break;
// 						}
// 						else
// 							lst1 = lst1->next;
// 					}
// 					lst2->moove += 1; //(ft_push_a(head_b, head_a) + ft_swap_a(head_a));
// 					break;
// 				}
// 			}
// 			else if (search_position(head_b, search) != 0)
// 				search--;
// 		}
// 		lst2 = lst2->next;
// 		if(lst2 != NULL && lst2->rank > nbs->div2)
// 		{
// 			lst2->moove += (1 + temp);//(ft_rotate_b(head_b); + reverse rotate pour remettre comme avant)
// 			temp += 1;
// 		}
// 	}
// 	return(check_best_option(head_b, nbs));
// }
