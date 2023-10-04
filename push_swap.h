/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:02 by nessie            #+#    #+#             */
/*   Updated: 2023/10/02 15:40:00 by nessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack {
	int				nbr;
	int				i;
	struct s_stack	*p;
}		t_stack;

// Main Functions
int		main(int argc, char **argv);
int		ft_error(int argc, char ***argv);

void	stack_init(t_stack **a, int argc, char **argv);
void	sort_a(t_stack **a, t_stack **b);

// Stack Utils
int		stacklen(t_stack *lst);
int		checkbackwards(t_stack **stack);

int		checkemptystack(t_stack **stack);
void	new_last_node(t_stack **stack, t_stack *new_node);
void	clean_stack(t_stack **stack);
t_stack	*last_node(t_stack *stack);

// Sorting Functions
void	three_values(t_stack **a);
void	four_values(t_stack **a, t_stack **b);
void	five_values(t_stack **a, t_stack **b);
void	radix(t_stack **a, t_stack **b);

// Swap
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Push
void	push(t_stack **stack_src, t_stack **stack_dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Rotate
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Reverse Rotate
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
