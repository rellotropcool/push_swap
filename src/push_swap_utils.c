/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:23:29 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:23:31 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_double	is_ext(int nb, t_stack *b)
{
	t_double	i;

	i.x = 0;
	if (!b)
		return (i.y = 0, i);
	while (b->value < (b->prev)->value)
	{
		b = b->next;
		i.x++;
	}
	i.x = -1 * si(b) / 2 + i.x;
	if (nb > b->value || nb < (b->prev)->value)
		return (i.y = 1, i);
	else
		return (i.y = 0, i);
}

void	pb_2(t_stack **a, t_stack **b, int bool)
{
	if (!(*b) || bool)
	{
		free_node(*b);
		(*b) = (*a);
		(*b)->next = (*b);
		(*b)->prev = (*b);
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*a)->next = *b;
		((*b)->prev)->next = *a;
		(*b)->prev = *a;
		*b = (*b)->prev;
	}
}

void	pb(t_stack **a, t_stack **b, int bool)
{
	t_stack	*save;

	save = (*a)->next;
	if ((*a)->next != *a)
	{
		((*a)->next)->prev = (*a)->prev;
		((*a)->prev)->next = (*a)->next;
	}
	else
		save = NULL;
	pb_2(a, b, bool);
	write(1, "pb\n", 3);
	*a = save;
}

void	pa_2(t_stack **b, t_stack **a)
{
	if (!(*b))
	{
		(*b) = (*a);
		(*b)->next = (*b);
		(*b)->prev = (*b);
	}
	else
	{
		(*a)->prev = (*b)->prev;
		(*a)->next = *b;
		((*b)->prev)->next = *a;
		(*b)->prev = *a;
		*b = (*b)->prev;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*save;

	save = (*a)->next;
	if ((*a)->next != *a)
	{
		((*a)->next)->prev = (*a)->prev;
		((*a)->prev)->next = (*a)->next;
	}
	else
		save = NULL;
	pa_2(b, a);
	write(1, "pa\n", 3);
	*a = save;
}
