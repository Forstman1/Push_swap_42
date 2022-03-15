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
	int				bestmoveb;
	int				bestmovea;
	int				score;
	struct s_ps		*next;
}	t_ps;

void	sa(t_ps **var, t_ps	**head);
void	sb(t_ps **var, t_ps	**head);
void	push(t_ps **var, t_ps **head, int i);
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
int		checkprevious(t_ps *var_a, t_ps *head_a, int j_value, int j, int *t);
void	pushingtostackb(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	reset(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	bestmoveinb(t_ps **var_b, t_ps **head_b);
int		checkmoves(t_ps *var ,t_ps **var_b, t_ps **head_b, int i);
void	sortingcount(t_ps	**var_a, t_ps	**head_a, int j);
void	bestmovea(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j);
void	pushtoa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j);
void	stack_sorting(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j);
void	pushtoaoptimazed(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b, int j);
void	bestscore(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	rrr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	pa_opt(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	sa_opt(t_ps **var, t_ps	**head);
void	ra_opt(t_ps **var_a, t_ps **head_a);
void	rra_opt(t_ps **var_a, t_ps **head_a);
void	pb_opt(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
void	sb_opt(t_ps **var, t_ps	**head);
void	rb_opt(t_ps **var_b, t_ps **head_b);
void	rrb_opt(t_ps **var_b, t_ps **head_b);
void	bestscore_for_a(t_ps **var_a, t_ps **head_a);
void	lis_test(t_ps	**var_a, t_ps	**head_a, t_ps	**head_fake, t_ps **tails, t_ps **tmp1, t_ps **tmp2);
void	pushingtostackb_v1(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
int		checkprevious_test(t_ps	*var_a, t_ps	*head_a, t_ps	*head_fake, int j_value, int j, int *t);








#endif