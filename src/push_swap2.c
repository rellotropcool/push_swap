/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:21:57 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:21:58 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	top_bot(t_double cheapest, t_stack **a, t_stack **b, t_double si)
{
	if (cheapest.x <= 0 && cheapest.y > 0)
	{
		while (cheapest.x-- > -1 * si.x / 2)
			ra(a);
		while (cheapest.y++ < si.y - si.y / 2)
			rrb(b);
	}
}

void	bot_top(t_double cheapest, t_stack **a, t_stack **b, t_double si)
{
	if (cheapest.x > 0 && cheapest.y <= 0)
	{
		while (cheapest.x++ < si.x - si.x / 2)
			rra(a);
		while (cheapest.y-- > -1 * si.y / 2)
			rb(b);
	}
}

void	turk_pb(t_stack **a, t_stack **b)
{
	t_double	cheapest;
	t_double	sir;

	cheapest.x = 2000000000;
	cheapest.y = 2000000000;
	cheapest.k = 2000000000;
	sir.x = si(*a);
	sir.y = si(*b);
	cheapest = cheapest_number(*a, *b, cheapest, *b);
	both_top(cheapest, a, b, sir);
	both_bot(cheapest, a, b, sir);
	top_bot(cheapest, a, b, sir);
	bot_top(cheapest, a, b, sir);
	pb(a, b, 0);
	if (si(*a) == 3)
		reset(b);
}

void	turk_pa(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*b)
	{
		if (((*a)->prev)->value > (*b)->value
			&& ((*a)->prev)->value < (*a)->value)
			while (((*a)->prev)->value > (*b)->value
				&& ((*a)->prev)->value < (*a)->value)
				rra(a);
		else if ((*b)->value > (*a)->value)
		{
			if (!((*b)->value > (*a)->prev->value))
				while ((*b)->value > (*a)->value
					&& (((*a)->prev->value > (*a)->value) || i++ == 0))
					ra(a);
		}
		pa(a, b);
	}
	while ((*a)->value > ((*a)->prev)->value)
		rra(a);
}

void	pouchsouap(t_stack **a, t_stack **b)
{
	if (check_sorted(*a))
		return ;
	if (si(*a) <= 3)
		tiny_sort(a);
	else
	{
		if (si(*a) > 3)
			pb(a, b, 1);
		if (si(*a) > 3)
			pb(a, b, 0);
		while (si(*a) > 3)
			turk_pb(a, b);
		tiny_sort(a);
		if (turk_pa2(a, b))
			return ;
		while (si(*b))
			turk_pa(a, b);
	}
}
