/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:52:01 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/08 18:10:04 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	long int		content;
	int				rank;

	int				pa;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;

	struct s_list	*next;
}	t_list;

typedef struct s_nbs
{
	int				count;
	int				div1;
	int				div2;
}	t_nbs;

//#################################
//#			   LIBFT	     	  #
//#################################

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str1);
int			ft_lstsize(t_list *lst);
int			ft_printf(const char *str, ...);

//#################################
//#			  Mod LIBFT  		  #
//#################################

long int	ft_mod_atol(const char *str);
void		ft_mod_free(t_list *lst);
void		ft_mod_lstadd_back(t_list **lst, t_list *new);
void		*ft_mod_lstlast(t_list **lst);
t_list		*ft_mod_new_lst(void);

//#################################
//#		   Parsing functions	  #
//#################################

void		*ft_parse_a(int argc, char **argv, t_list *head_a);
void		*ft_parse_one_arg(t_list *head_a, t_list *pile_a, char *str);
void		*ft_str_check(char *str);
int			ft_int_check_lst(t_list *head, long int *search);
void		ft_ranking(t_list *head_a, t_list *pile_a);

//#################################
//#	 Parsing functions if 1 arg	  #
//#################################

void		*ft_parse_1_arg(char **split, t_list *head_a);
int			ft_count_rows(char **tab);
void		ft_free_split(char **split);
char		**ft_split(char *str);
void		*ft_verif_str(char **split, char *str, int i);
int			ft_is_delimiter(char c);
int			ft_words_count(char *str);
int			ft_one_word_len(char *str);

//#################################
//#	     		ERROR 			  #
//#################################

void		ft_error(void);

//#################################
//#	     		 SWAP		      #
//#################################

void		*ft_swap(t_list **lst);
void		*ft_swap_a(t_list **lst);
void		*ft_swap_b(t_list **lst);
void		*ft_swap_ab(t_list **lst1, t_list **lst2);

//#################################
//#	     		 PUSH		      #
//#################################

void		*ft_push(t_list **source, t_list **destination);
void		*ft_push_a(t_list **lst2, t_list **lst1);
void		*ft_push_b(t_list **lst1, t_list **lst2);

//#################################
//#	     		ROTATE		      #
//#################################

void		*ft_rotate(t_list **lst);
void		*ft_rotate_a(t_list **lst_A);
void		*ft_rotate_b(t_list **lst_B);
void		*ft_rotate_ab(t_list **lst1, t_list **lst2);

//#################################
//#	     REVERSE ROTATE		      #
//#################################

void		*ft_reverse_rotate_a(t_list **lst_A);
void		*ft_reverse_rotate_b(t_list **lst_B);
void		*ft_reverse_rotate_ab(t_list **lst_A, t_list **lst_B);
void		*ft_reverse_rotate(t_list **lst);

//#################################
//#	    	   ALGO MAIN	      #
//#################################

void		ft_algo(t_list **head_a, t_list **head_b, t_nbs *nbs);

int			ft_is_sorted(t_list **head);

void		ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void		ft_tri_three_a(t_list **head_a);

void		ft_reset_ops(t_list **head);
void		ft_fill_ops(t_list **head_a, t_list **head_b);
void		ft_fill_ops_a(t_list **head_a, t_list *lst1, t_list *lst2);
void		ft_calcul_ops(t_list **head);
void		ft_calcul_ops_2(t_list *lst);
void		ft_exec_ops(t_list **head_a, t_list **head_b);
void		ft_do_ops(t_list **head, t_list **head_a, t_list **head_b);

void		ft_putsmallest_up(t_list **head);

//#################################
//#	    	   ALGO UTILS	      #
//#################################

void		*ft_init_struct(t_nbs *nbs, t_list **head_a, t_list **head_b);
void		ft_fill_struct(t_list **head, t_nbs *nbs);
int			count_rank(t_list	**head);
int			count_lst(t_list **head);
int			search_position(t_list **head, int search);
int			check_is_smallest(t_list **head_a);
int			ft_sm(t_list **head_a, int rank_b);
int			ft_bg(t_list **head_a, int rank_b);
int			ft_last_rank(t_list **head);
int			ft_big_a(t_list **head);
int			ft_small_a(t_list **head);
int			ft_bg2(t_list **head_a, t_list *lst1, t_list *lst2, int temp);
int			ft_sm2(t_list **head_a, t_list *lst1, t_list *lst2, int temp);
int			ft_check_one_and_last(t_list **head_a, t_list *lst1, \
			t_list *lst2, int temp);
void		ft_check_rank_and_next(t_list **head_a, t_list *lst1, \
			t_list *lst2, int temp);

#endif
