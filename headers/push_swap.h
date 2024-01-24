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
	int				*nb_list;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;


//#################################
//#			LIBFT functions		  #
//#################################

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str1);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew();
long int	ft_atol(const char *str);//modify not libft

//#################################
//#		   Parsing functions	  #
//#################################

void	*ft_parse_a(int argc, char **argv, t_list *head_a);
void	*ft_parse_one_arg(t_list *head_a, t_list *pile_a, char *str);
void	*ft_str_check(char *str);
int		ft_int_check_lst(t_list *head,long int *search);
void	ft_print_piles(t_list *head_a, t_list *head_b);

//#################################
//#	     error + rank + clean     #
//#################################

void	ft_error();
void	ft_ranking(int argc, t_list *head_a, t_list *pile_a);
void	ft_free_lst(t_list *lst);//modify not libft


void	*ft_swap(t_list **lst);
void	*ft_swap_a(t_list **lst);
void	*ft_swap_b(t_list **lst);
void	*ft_swap_ab(t_list **lst1, t_list **lst2);

void	*ft_push(t_list** source, t_list** destination);
void	*ft_push_a(t_list **lst2, t_list **lst1);
void	*ft_push_b(t_list **lst1, t_list **lst2);

void	*ft_rotate(t_list **lst);
void	*ft_rotate_a(t_list **lst_A);
void	*ft_rotate_b(t_list **lst_B);
void	*ft_rotate_ab(t_list **lst1, t_list **lst2);

void	*ft_reverse_rotate_a(t_list **lst_A);
void	*ft_reverse_rotate_b(t_list **lst_B);
void	*ft_reverse_rotate_ab(t_list **lst_A, t_list **lst_B);
void	*ft_reverse_rotate(t_list **lst);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_lstlast(t_list **lst);

#endif