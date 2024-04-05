/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:09:29 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:09:30 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**array_cpy(char **str)
{
	int		i;
	char	**exit;

	i = 0;
	while (str[i])
		i++;
	exit = malloc((i + 1) * sizeof(char *));
	if (!exit)
		return (NULL);
	i = 0;
	while (str[i])
	{
		exit[i] = ft_strdup(str[i]);
		i++;
	}
	exit[i] = 0;
	return (exit);
}

void	free_node(t_stack *a)
{
	a->value = 0;
	if (a->next)
		a->next->prev = NULL;
	a->next = NULL;
	if (a->prev)
		a->prev->next = NULL;
	a->prev = NULL;
	free(a);
}

void	free_stack(t_stack *a)
{
	t_stack	*save;

	save = NULL;
	if (!a)
		return ;
	while (a && a->next)
	{
		save = a->next;
		free_node(a);
		a = save;
	}
	if (a)
		free_node(a);
}

int	main(int ac, char **av)
{
	int		k;
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (1);
	a = ft_lstnew(0);
	b = ft_lstnew(0);
	k = parse_entry(ac, av, a);
	if (!k)
		return (write(2, "Error\n", 7), free_stack(a), free_stack(b), 1);
	else if (k == 2)
		return (free_stack(a), free_stack(b), 0);
	chain_back(a);
	pouchsouap(&a, &b);
	return (free_stack(a), free_stack(b), 0);
}
