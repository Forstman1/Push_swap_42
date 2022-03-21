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

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "libft/libft.h"

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

typedef struct s_stack
{
	t_ps	*var_a;
	t_ps	*var_b;
	t_ps	*head_a;
	t_ps	*head_b;
}	t_stack;

void	sa(t_ps **var, t_ps	**head);
void	sb(t_ps **var, t_ps	**head);
void	push(t_ps **var, t_ps **head, int i);
void	ft_lstadd(t_ps **lst, t_ps **head, t_ps *new);
void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps	**head_b);
void	pb(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	pa(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	ra(t_ps **var_a, t_ps **head_a);
void	rb(t_ps **var_b, t_ps **head_b);
void	rr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	rra(t_ps **var_a, t_ps **head_a);
void	rrb(t_ps **var_b, t_ps **head_b);
void	lis(t_ps **var_a, t_ps **head);
int		checkprevious(t_ps	*var_a, t_ps	*head_a, int j_value, int *t);
void	pushingtostackb(t_stack *stacks);
void	reset(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	bestmoveinb(t_ps **var_b, t_ps **head_b);
int		checkmoves(t_ps *var, t_ps **var_b, t_ps **head_b, int i);
void	sortingcount(t_ps **var_a, t_ps **head_a, int j);
void	bestmovea(t_ps	**var_a, t_ps	**var_b, t_stack *stacks);
void	pushtoaoptimazed(t_stack *stacks);
void	bestscore(t_ps **var_b, t_ps **head_b);
void	rrr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	pa_opt(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	sa_opt(t_ps **var, t_ps	**head);
void	ra_opt(t_ps **var_a, t_ps **head_a);
void	rra_opt(t_ps **var_a, t_ps **head_a);
void	pb_opt(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	sb_opt(t_ps **var, t_ps	**head);
void	rb_opt(t_ps **var_b, t_ps **head_b);
void	rrb_opt(t_ps **var_b, t_ps **head_b);
void	reset_to_smallist_number(t_ps	**var_a, t_ps	**head_a, int j);
void	checkvalid(char *str);
void	checkduplicate(char	**splited, int i);
int		smallistnumber(t_ps **var_a);
void	reset2(t_stack	*stacks);
void	bestmove_for_a(t_ps **var_a, t_ps **head_a);
int		smallistscore(t_ps **var_a);
void	optimazed_rules(t_ps	*lst_b, t_stack	*stacks);
void	rulesfor_a(t_ps	*lst_b, t_stack	*stacks);
void	rulesfor_b(t_ps	*lst_b, t_stack	*stacks);
int		lenghtoflist(t_ps	*lst);
char	**parsing(char **argv, int *i);
void	switching_sb_sa(t_ps	*lst);
void	reversing_a_b(t_ps	*lst);
void	bestscore_for_a(t_stack *stacks);
void	r_reversing_a(t_ps	*lst);
void	stack_sorting(t_stack *stacks, int j);

#endif