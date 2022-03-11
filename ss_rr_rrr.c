

#include "push_swap.h"


void	ss(t_ps **var_a, t_ps **head_a, t_ps **var_b, t_ps	**head_b)
{
	sa(var_a, head_a);
	sb(var_b, head_b);
}

void	rr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	ra_opt(var_a, head_a);
	rb_opt(var_b, head_b);
	*var_a = *head_a;
	*var_b = *head_b;
	//printf("rr\n");
}

void	rrr(t_ps	**var_a, t_ps **head_a, t_ps **var_b, t_ps **head_b)
{
	rra_opt(var_a, head_a);
	rrb_opt(var_b, head_b);
	*var_a = *head_a;
	*var_b = *head_b;
	//printf("rrr\n");
}