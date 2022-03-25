/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:37:13 by sahafid           #+#    #+#             */
/*   Updated: 2022/03/18 00:37:15 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	sa_opt(var_a, head_a);
	sb_opt(var_b, head_b);
	*var_a = *head_a;
	*var_b = *head_b;
	write(1, "ss\n", 3);
}

void	rr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	ra_opt(var_a, head_a);
	rb_opt(var_b, head_b);
	*var_a = *head_a;
	*var_b = *head_b;
	write(1, "rr\n", 3);
}

void	rrr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	(*var_a)->previous = NULL;
	(*var_b)->previous = NULL;
	rra_opt(var_a, head_a);
	rrb_opt(var_b, head_b);
	*var_a = *head_a;
	*var_b = *head_b;
	write(1, "rrr\n", 4);
}
