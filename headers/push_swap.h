#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>


typedef	struct s_list
{
	long int		*content;
	int				*rank;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

//#################################
//#			   LIBFT	     	  #
//#################################

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str1);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
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

#endif