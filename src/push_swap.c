/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:45 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:18:46 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reset(t_stack **b)
{
	int		i;
	t_stack	*save;

	i = 0;
	save = *b;
	while ((*b)->value > ((*b)->next)->value)
	{
		*b = (*b)->next;
		i++;
	}
	*b = save;
	if (i <= si(*b) / 2)
		while ((*b)->value < ((*b)->prev)->value)
			rb(b);
	else
		while ((*b)->value < ((*b)->prev)->value)
			rrb(b);
}

void	tiny_sort(t_stack **a)
{
	if ((*a)->value > ((*a)->next)->value && (*a)->value > ((*a)->prev)->value)
		ra(a);
	else if (((*a)->next)->value > ((*a)->prev)->value
		&& ((*a)->next)->value > (*a)->value)
		rra(a);
	if ((*a)->value > ((*a)->next)->value)
		sa(a);
}

t_double	cheapest_number(t_stack *a, t_stack *b, t_double be, t_stack *start)
{
	int	i;
	int	j;

	i = -1 * si(a) / 2 - 1;
	while (++i < si(a) - si(a) / 2)
	{
		j = -1 * si(b) / 2 - 1;
		while (++j < si(b) - si(b) / 2)
		{
			if (is_ext(a->value, start).y && be.k > si(a) - si(a) / 2 - abs(i)
				+ si(b) - si(b) / 2 - abs(is_ext(a->value, start).x))
				return (be.x = i, be.y = is_ext(a->value, start).x, be);
			else if (a->value > b->value && a->value < (b->prev)->value
				&& be.k > si(a) - si(a) / 2 - abs(i) + si(b) - si(b) / 2
				- abs(j))
			{
				be.x = i;
				be.y = j;
				be.k = si(a) - si(a) / 2 - abs(i) + si(b) - si(b) / 2 - abs(j);
			}
			b = b->next;
		}
		a = a->next;
	}
	return (be);
}

void	both_top(t_double cheapest, t_stack **a, t_stack **b, t_double si)
{
	if (cheapest.x <= 0 && cheapest.y <= 0)
	{
		while (cheapest.x > -1 * si.x / 2 && cheapest.y > -1 * si.y / 2)
		{
			cheapest.x--;
			cheapest.y--;
			rr(a, b);
		}
		while (cheapest.x-- > -1 * si.x / 2)
			ra(a);
		while (cheapest.y-- > -1 * si.y / 2)
			rb(b);
	}
}

void	both_bot(t_double cheapest, t_stack **a, t_stack **b, t_double si)
{
	if (cheapest.x > 0 && cheapest.y > 0)
	{
		while (cheapest.x < si.x - si.x / 2 && cheapest.y < si.y - si.y / 2)
		{
			cheapest.x++;
			cheapest.y++;
			rrr(a, b);
		}
		while (cheapest.x++ < si.x - si.x / 2)
			rra(a);
		while (cheapest.y++ < si.y - si.y / 2)
			rrb(b);
	}
}
