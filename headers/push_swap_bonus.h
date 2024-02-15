/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:52:01 by gchamore          #+#    #+#             */
/*   Updated: 2024/02/15 10:32:44 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

//#################################
//#	    	   CHECKER	      #
//#################################

int			ft_do_swp_and_psh(t_list2 **head_a, t_list2 **head_b, \
			char *instruction);
int			ft_do_rot_and_revrot(t_list2 **head_a, t_list2 **head_b, \
			char *instruction);
int			ft_do_instructions(t_list2 **head_a, t_list2 **head_b, \
			char *instruction);
int			verif_instructions(t_list2 **head_a, t_list2 **head_b);

#endif
