#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstclear(t_stack **lst);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_super_lstsize(t_stack **lst);
t_stack				*ft_lstnew(int content);
char				**ft_split(char const *s, char c);
int					parse_entry(int ac, char **entry, t_stack *stack);
void				chain_back(t_stack *stack_a);
int					is_extreme(int nb, t_stack *stack_b, int *count);
void				pb(t_stack **stack_a, t_stack **stack_b, int *count);
void				pa(t_stack **stack_a, t_stack **stack_b, int *count);
void				rb(t_stack **stack_b, int *count);
void				rrb(t_stack **stack_b, int *count);

#endif
