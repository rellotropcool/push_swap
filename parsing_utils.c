#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = content;
	new->prev = NULL;
	return (new);
}

int	ft_super_lstsize(t_stack **lst)
{
	int		i;
	t_stack	*start;

	if (!lst || !(*lst))
		return (0);
	i = 1;
	start = *lst;
	while ((*lst)->next != start)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*save;

	if (!lst || !(*lst))
		return ;
	save = (*lst)->next;
	ft_lstclear(&save);
	free(*lst);
	(*lst) = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (lst && lst->next)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *current;

	if (!lst)
		return ;
	current = ft_lstlast(*lst);
	if (current)
		current->next = new;
	else
		(*lst) = new;
}
