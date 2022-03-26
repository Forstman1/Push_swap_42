/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:16:58 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 16:16:59 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

char	*get_next_line(void);
void	pa(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	sa(t_ps **var, t_ps	**head);
void	ra(t_ps **var_a, t_ps **head_a);
void	rra(t_ps **var_a, t_ps **head_a);
void	pb(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	sb(t_ps **var, t_ps	**head);
void	rb(t_ps **var_b, t_ps **head_b);
void	rrb(t_ps **var_b, t_ps **head_b);
void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	rr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
void	rrr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b);
char	**parsings(char **argv, int *i);
void	ft_lstadd(t_ps **lst, t_ps **head, t_ps *new);
void	switching_sb_sa(t_ps	*lst);
void	reversing_a_b(t_ps	*lst);
void	push(t_ps **var, t_ps **head, int i);
void	check_rules(char	*str, t_stack *stacks);
void	check_everything(t_stack	*stacks);
void	free_everything(t_stack	*stacks);
void	check_sorting(t_stack	*stacks);
void	error_duplicate(char	**splited, int *array);
void	free_parsing(char	**splited);
void	error(void);
char	**parsing_utils(char	**splited, char	**argv, int i);
void	checkmaxint(char	**splited, int t);
void	checkvalid(char *str);
int		stack_a_rules(t_stack *stacks, char	*str);

#endif