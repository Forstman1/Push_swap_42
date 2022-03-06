/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:12:10 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/27 14:12:12 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




typedef struct s_ps
{
	struct s_ps		*previous;
	int				number;
	int				index;
	int				subsequence;
	int				count;
	int				lic;
	struct s_ps		*next;
}	t_ps;

void	sa(t_ps **var, t_ps	**head);
void	sb(t_ps **var, t_ps	**head);
void	push(t_ps **var, t_ps **head, t_ps **tail, int i);
void	ft_lstadd_front(t_ps **lst, t_ps **head, t_ps *new);
void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps	**head_b);
void	pb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	pa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	ra(t_ps **var_a, t_ps **head_a);
void	rb(t_ps **var_b, t_ps **head_b);
void	rr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	rra(t_ps **var_a, t_ps **head_a);
void	rrb(t_ps **var_b, t_ps **head_b);
void	lis(t_ps **var_a, t_ps **head);
int	checkprevious(t_ps	*var_a, t_ps	*head_a, int j_value, int j, int *t);

#endif