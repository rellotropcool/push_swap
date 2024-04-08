/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:45 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:18:46 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reset_a(t_stack **a)
{
	int		i;
	t_stack	*save;

	i = 0;
	save = *a;
	while ((*a)->value < ((*a)->next)->value)
	{
		*a = (*a)->next;
		i++;
	}
	*a = save;
	if (i <= si(*a) / 2)
		while ((*a)->value > ((*a)->prev)->value)
			ra(a);
	else
		while ((*a)->value > ((*a)->prev)->value)
			rra(a);
}
