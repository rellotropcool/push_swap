/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule-bre <rellotropcool@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:24:29 by aule-bre          #+#    #+#             */
/*   Updated: 2024/03/26 14:24:30 by aule-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_double
{
	int				x;
	int				y;
	int				k;
}					t_double;

void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstclear(t_stack **lst);
t_stack				*ft_lstlast(t_stack *lst);
int					si(t_stack *lst);
t_stack				*ft_lstnew(int content);
char				**ft_split(char const *s, char c);
char				**ft_free(char **str);
void				ft_lstclear(t_stack **lst);
int					parse_entry(int ac, char **entry, t_stack *stack);
void				chain_back(t_stack *stack_a);
t_double			is_ext(int nb, t_stack *stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b, int bool);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rrb(t_stack **stack_b);
void				printf_stack(t_stack *a);
int					abs(int i);
int					turk_pa2(t_stack **a, t_stack **b);
void				top_bot(t_double cheapest, t_stack **a, t_stack **b,
						t_double si);
void				bot_top(t_double cheapest, t_stack **a, t_stack **b,
						t_double si);
void				both_top(t_double cheapest, t_stack **a, t_stack **b,
						t_double si);
void				both_bot(t_double cheapest, t_stack **a, t_stack **b,
						t_double si);
void				turk_pb(t_stack **a, t_stack **b);
void				turk_pa(t_stack **a, t_stack **b);
void				pouchsouap(t_stack **a, t_stack **b);
t_double			cheapest_number(t_stack *a, t_stack *b, t_double be,
						t_stack *start);
void				tiny_sort(t_stack **a);
void				reset(t_stack **b);
void				free_node(t_stack *a);
char				**array_cpy(char **str);
int					check_sorted(t_stack *a);

#endif
