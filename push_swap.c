/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:23:33 by sahafid           #+#    #+#             */
/*   Updated: 2022/02/26 12:23:34 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	ft_lstadd_back(t_ps **lst, t_ps *new)
{
	t_ps	*root;

	root = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (root->next != NULL)
			root = root->next;
		root->next = new;
		new->previous = root;
	}
}



void	push(t_ps **var, t_ps **head, char *s, int i)
{
	t_ps	*tmp;

	tmp = (t_ps*)malloc(sizeof(t_ps));

	tmp->a = atoi(s);

	if (i == 1)
		*head = tmp;

	printf("%d\n", tmp->a);

	tmp->next = NULL;
	ft_lstadd_back(var, tmp);
}

void	sa(t_ps **var, t_ps *head)
{

}

int main(int argc, char *argv[])
{
	t_ps	*var;
	t_ps	*head;
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc > 2)
	{
		while(argv[i])
		{
			while (argv[i][j])
			{
				if (!(isdigit(argv[i][j])))
					return 0;
				j++;
			}
			i++;
		}
		i = 1;
		while (argv[i])
		{
			push(&var, &head, argv[i], i);	
			i++;
		}
		var = head;
		var = var->next;
		printf("%d\n", var->a);
		var = var->next;
		printf("%d\n", var->a);
		var = var->previous;
		printf("%d\n", var->a);
		//sa(&var, head);
		// sb();
		// ss();

	}
	return 0;
}