#include "push_swap.h"

int	is_extreme(int nb, t_stack *stack_b, int *count)
{
	if (*count == 0)
		return (2);
	while (stack_b->next && stack_b->value > (stack_b->next)->value)
		stack_b = stack_b->next;
	if (nb < stack_b->value)
		return (1);
	else if (nb > (stack_b->next)->value)
		return (2);
	else
		return (0);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack	*save;

	save = (*stack_a)->next;
	if ((*stack_a)->next != *stack_a)
	{
		((*stack_a)->next)->prev = (*stack_a)->prev;
		((*stack_a)->prev)->next = (*stack_a)->next;
	}
	else
		save = NULL;
	if (!(*stack_b) || *count == 0)
	{
		(*stack_b) = (*stack_a);
		(*stack_b)->next = (*stack_b);
		(*stack_b)->prev = (*stack_b);
	}
	else
	{
		(*stack_a)->prev = (*stack_b)->prev;
		(*stack_a)->next = *stack_b;
		((*stack_b)->prev)->next = *stack_a;
		(*stack_b)->prev = *stack_a;
		*stack_b = (*stack_b)->prev;
	}
	write(1, "pb\n", 3);
	(*count)++;
	*stack_a = save;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int *count)
{
	t_stack	*save;

	save = (*stack_a)->next;
	if ((*stack_a)->next != *stack_a)
	{
		((*stack_a)->next)->prev = (*stack_a)->prev;
		((*stack_a)->prev)->next = (*stack_a)->next;
	}
	else
		save = NULL;
	if (!(*stack_b) || *count == 0)
	{
		(*stack_b) = (*stack_a);
		(*stack_b)->next = (*stack_b);
		(*stack_b)->prev = (*stack_b);
	}
	else
	{
		(*stack_a)->prev = (*stack_b)->prev;
		(*stack_a)->next = *stack_b;
		((*stack_b)->prev)->next = *stack_a;
		(*stack_b)->prev = *stack_a;
		*stack_b = (*stack_b)->prev;
	}
	write(1, "pa\n", 3);
	(*count)++;
	*stack_a = save;
}

void	rb(t_stack **stack_b, int *count)
{
	*stack_b = (*stack_b)->next;
	write(1, "rb\n", 3);
	(*count)++;
}

void	rrb(t_stack **stack_b, int *count)
{
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
	(*count)++;
}
