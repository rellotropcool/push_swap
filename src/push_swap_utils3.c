/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:23:45 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:23:46 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(t_stack **b)
{
	*b = (*b)->next;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}

int	abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

int	check_sorted(t_stack *a)
{
	t_stack	*save;

	save = a->prev;
	while (a->value < a->next->value && a != save)
		a = a->next;
	if (a == save)
		return (1);
	return (0);
}

int	turk_pa2(t_stack **a, t_stack **b)
{
	if (si(*b) != 2)
		return (0);
	while (*b)
	{
		while ((*a)->value < (*b)->value)
		{
			ra(a);
			if ((*a)->value < (*a)->prev->value)
				break ;
		}
		pa(a, b);
		while ((*a)->value > ((*a)->prev)->value)
			rra(a);
	}
	return (1);
}
