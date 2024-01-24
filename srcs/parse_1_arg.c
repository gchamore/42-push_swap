/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:57:19 by gchamore          #+#    #+#             */
/*   Updated: 2024/01/24 17:04:36 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	*parse_if_one_arg(int argc, char **argv)
{
	if(argc == 2)
	{
		
	}
	else
		return NULL;
	return (str);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!new)
// 		return ;
// 	if (!(*lst))
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = *lst;
// 	while (last->next)
// 		last = last->next;
// 	last->next = new;
// }

// void	*parse_if_one_arg(int argc, char **argv)
// {
// 	t_list	*pile_a;
// 	t_list	*head;

// 	pile_a = NULL;
// 	head = NULL;

// 	int i = 1;
// 	while (i < argc)
// 	{
// 			int len = ft_strlen(argv[i]);
// 			for (int j = 0; j < len; j++)
// 			{
// 				char *num_str = (char *)malloc(2);
// 				if (!num_str)
// 				{
// 					fprintf(stderr, "Erreur d'allocation mémoire\n");
// 					while (head != NULL)
// 					{
// 						t_list *next = head->next;
// 						free(head);
// 						head = next;
// 					}

// 					return 1;
// 				}

// 				strncpy(num_str, &argv[i][j], 1);
// 				num_str[1] = '\0';

// 				t_list *new_node = ft_lstnew(num_str);
// 				if (!new_node)
// 				{
// 					fprintf(stderr, "Erreur d'allocation mémoire\n");

// 					while (head != NULL)
// 					{
// 						t_list *next = head->next;
// 						free(head);
// 						head = next;
// 					}

// 					free(num_str);
// 					return 1;
// 				}

// 				ft_lstadd_back(&head, new_node);

// 				free(num_str);
// 			}

// 			i++;
// 		}

// 		printf("Liste :\n");
// 		printf("Taille : %d\n", ft_lstsize(head));

// 		t_list *current = head;
// 		while (current != NULL)
// 		{
// 			printf("%s\n", (char *)current->content);
// 			current = current->next;
// 		}
// 	}

// 	while (head != NULL)
// 	{
// 		t_list *next = head->next;
// 		free(head);
// 		head = next;
// 	}

	return 0;
}