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


void	checkvalid(char *str);
void	checkduplicate(char	**splited, int i);
char	*get_next_line(int fd);
// void	pa(t_ps **var_a, t_ps **head_a ,t_ps **var_b, t_ps **head_b);
// void	sa(t_ps **var, t_ps	**head);
// void	ra(t_ps **var_a, t_ps **head_a);
// void	rra(t_ps **var_a, t_ps **head_a);

#endif