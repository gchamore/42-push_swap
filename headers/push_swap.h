#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>


typedef	struct s_list
{
	long int		content;
	int				rank;
	int				moove;

	int				pa;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;

	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_nbs
{
    int		count;
    int		div1;
	int		div2;
	int		best_pos_rank;
	int		best_pos_moove;
	int 	best_neg_rank;
	int 	best_neg_moove;
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

long int	ft_atol(const char *str);
char		**ft_split(char *str);
void		*verif_str(char **split, char *str, int i);
void		ft_free(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		*ft_lstlast(t_list **lst);
t_list		*ft_new_lst();

//#################################
//#		   Parsing functions	  #
//#################################

void	*ft_parse_a(int argc, char **argv, t_list *head_a);
void	*ft_parse_one_arg(t_list *head_a, t_list *pile_a, char *str);
void	*ft_str_check(char *str);
int		ft_int_check_lst(t_list *head,long int *search);
void	ft_print_piles(t_list *head_a, t_list *head_b);
void	ft_ranking(t_list *head_a, t_list *pile_a);

//#################################
//#	 Parsing functions if 1 arg	  #
//#################################

void	*ft_parse_1_arg(char **split, t_list *head_a);
int		count_rows(char **tab);
void	free_split(char **split);

//#################################
//#	     		ERROR 			  #
//#################################

void	ft_error();

//#################################
//#	     		 SWAP		      #
//#################################

void	*ft_swap(t_list **lst);
void	*ft_swap_a(t_list **lst);
void	*ft_swap_b(t_list **lst);
void	*ft_swap_ab(t_list **lst1, t_list **lst2);

//#################################
//#	     		 PUSH		      #
//#################################

void	*ft_push(t_list** source, t_list** destination);
void	*ft_push_a(t_list **lst2, t_list **lst1);
void	*ft_push_b(t_list **lst1, t_list **lst2);

//#################################
//#	     		ROTATE		      #
//#################################

void	*ft_rotate(t_list **lst);
void	*ft_rotate_a(t_list **lst_A);
void	*ft_rotate_b(t_list **lst_B);
void	*ft_rotate_ab(t_list **lst1, t_list **lst2);

//#################################
//#	     REVERSE ROTATE		      #
//#################################

void	*ft_reverse_rotate_a(t_list **lst_A);
void	*ft_reverse_rotate_b(t_list **lst_B);
void	*ft_reverse_rotate_ab(t_list **lst_A, t_list **lst_B);
void	*ft_reverse_rotate(t_list **lst);

//#################################
//#	    		 ALGO		      #
//#################################

int		count_rank(t_list	**head);
void	ft_algo_pre_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	fill_struct(t_list **head, t_nbs *nbs);
void	*init_struct(t_nbs *nbs, t_list **head_a, t_list **head_b);
void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	ft_middle_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	ft_little_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	algo_tri(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	quick_sort_big(t_list **head_a, t_list **head_b, t_nbs *nbs);
int		count_lst(t_list **head);
int		which_part(t_list **head, int search);
int		search_position(t_list **head, int search);
void	ft_put_search_first_a(t_list **head_a, int search);
t_list	*check_best_option(t_list **head_b, t_nbs *nbs);
t_list	*ft_tell_me_positiv(t_list **head_a, t_list **head_b, t_nbs *nbs);
t_list	*ft_tell_me_negativ(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	putsmallest_up(t_list **head);
int		check_is_smallest(t_list **head_a);
int		check_if_biggest(t_list **head_a, int rank_b);
void	ft_tri_three_a(t_list **head_a);
int		ft_is_sorted(t_list **head);
// void	ft_big_tri(t_list **head_a, t_list **head_b, t_nbs *nbs, int compteur);

int		ft_check_if_small(t_list **head_a, int rank_b);
int		ft_check_if_big(t_list **head_a, int rank_b);
void	ft_reset_ops(t_list **head);
int		ft_last_rank(t_list **head);
int		ft_big_a(t_list **head);
int		ft_small_a(t_list **head);
void	ft_fill_ops_a(t_list **head_a, t_list *lst1, t_list *lst2);
void	ft_fill_ops(t_list **head_a, t_list **head_b);
void	ft_calcul_ops(t_list **head);
void	ft_algo_new(t_list **head_a, t_list **head_b, t_nbs *nbs);
void	ft_do_ops(t_list **head, t_list **head_a, t_list **head_b);
void	ft_exec_ops(t_list **head_a, t_list **head_b);



#endif
