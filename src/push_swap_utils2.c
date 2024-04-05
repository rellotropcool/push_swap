/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:23:37 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:23:38 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack **a)
{
	*a = (*a)->next;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	*a = (*a)->prev;
	write(1, "rra\n", 4);
}

void	rr(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	write(1, "rrr\n", 4);
}

void	sa(t_stack **a)
{
	int	save;

	save = (*a)->value;
	(*a)->value = ((*a)->next)->value;
	((*a)->next)->value = save;
	write(1, "sa\n", 3);
}
