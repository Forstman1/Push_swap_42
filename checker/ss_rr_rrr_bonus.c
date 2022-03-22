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

#include "checker.h"

void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	sa(var_a, head_a);
	sb(var_b, head_b);
}

void	rr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	ra(var_a, head_a);
	rb(var_b, head_b);
}

void	rrr(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	rra(var_a, head_a);
	rrb(var_b, head_b);
}
