#include "push_swap.h"

void	printf_stack(t_stack *a)
{
	int	save;

	if (!a)
		return ;
	save = a->value;
	printf("%d\n", a->value);
	if (a->next)
		a = a->next;
	while (a->next && a->value != save)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}

int	position(t_stack *stack_a, t_stack **stack_b, int *count)
{
	int	i;

	i = 0;
	while (stack_a->value < (*stack_b)->value)
	{
		i++;
		rb(stack_b, count);
	}
	return (i);
}

void	reset(t_stack **stack_b, int *count, int pos)
{
	int	size;

	size = ft_super_lstsize(stack_b);
	if (pos > size / 2)
		while ((*stack_b)->value > ((*stack_b)->next)->value)
			rb(stack_b, count);
	else
		while ((*stack_b)->value < ((*stack_b)->prev)->value)
			rrb(stack_b, count);
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	count;
	int	pos;

	count = 0;
	while (*stack_a)
	{
		printf("Stack A\n");
		printf_stack(*stack_a);
		printf("Stack B\n");
		printf_stack(*stack_b);
		i = is_extreme((*stack_a)->value, *stack_b, &count);
		if (count == 0 || i)
        {
			pb(stack_a, stack_b, &count);
            if (i == 1)
			    rb(stack_b, &count);
        }
		else
		{
			pos = position(*stack_a, stack_b, &count);
			pb(stack_a, stack_b, &count);
            printf("Stack A\n");
		    printf_stack(*stack_a);
		    printf("Stack B\n");
		    printf_stack(*stack_b);
			reset(stack_b, &count, pos);
		}
	}
	while (*stack_b)
	{
        printf("Stack A\n");
		printf_stack(*stack_a);
		printf("Stack B\n");
		printf_stack(*stack_b);
		pa(stack_b, stack_a, &count);
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_stack *stack_a = ft_lstnew(0);
	t_stack *stack_b = ft_lstnew(0);

	if (ac <= 1)
		return (0);
	if (!parse_entry(ac, av, stack_a))
		return (write(1, "Error\n", 7), 0);
	chain_back(stack_a);
	printf("Total %d\n", push_swap(&stack_a, &stack_b));
    printf("Final A\n");
	printf_stack(stack_a);
	return (1);
}
