/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:34 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:18:36 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicate(int nb, t_stack *current)
{
	if (current)
	{
		if (current->value == nb)
			return (0);
		return (check_duplicate(nb, current->next));
	}
	return (1);
}

int	ft_superatoi(int *number, char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	*number = nb * sign;
	if (str[i])
		return (0);
	if (nb * sign > 2147483647 || nb * sign < -2147483648)
		return (0);
	return (1);
}

int	parse_number(int i, char *str, t_stack *stack)
{
	int	nb;

	nb = 0;
	if (!ft_superatoi(&nb, str))
		return (0);
	if (i && !check_duplicate((int)nb, stack))
		return (0);
	if (i == 0)
		stack->value = nb;
	else
		ft_lstadd_back(&stack, ft_lstnew(nb));
	return (1);
}

int	parse_entry(int ac, char **entry, t_stack *stack)
{
	int		i;
	char	**str;

	i = -1;
	if (ac == 2)
		str = ft_split(entry[1], ' ');
	else
		str = array_cpy(&entry[1]);
	while (str[++i])
	{
		if (!parse_number(i, str[i], stack))
			return (ft_free(str), 0);
	}
	if (i == 1)
		return (ft_free(str), 2);
	return (ft_free(str), 1);
}

void	chain_back(t_stack *stack_a)
{
	t_stack	*save_start;
	t_stack	*save;

	save_start = stack_a;
	while (stack_a && stack_a->next)
	{
		save = stack_a;
		stack_a = stack_a->next;
		stack_a->prev = save;
	}
	stack_a->next = save_start;
	save_start->prev = stack_a;
}
