#include "push_swap.h"

int	check_duplicate(int nb, t_stack *current)
{
	if (current)
	{
		if (current->value == nb)
			return (write(1, "duplicate\n", 11), 0);
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
		return (write(1, "invalid char\n", 14), 0);
	if (nb * sign > 2147483647 || nb * sign < -2147483648)
		return (write(1, "number too large\n", 18), 0);
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
	{
		stack->value = nb;
	}
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
		str = &entry[1];
	while (str[++i])
	{
		if (!parse_number(i, str[i], stack))
			return (0);
	}
	return (1);
}

void	chain_back(t_stack *stack_a)
{
	t_stack *save_start;
	t_stack *save;

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
