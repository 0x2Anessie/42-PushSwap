#include "push_swap.h"

/**
 * @brief Fait l'inverse de la fonction rotate.
 */
void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stacklen(*stack) <= 1)
		ft_putendl_fd("Stack is empty or has only one element", 1);
	last = last_node(*stack);
	first = *stack;
	*stack = first->p;
	last->p = first;
	first->p = NULL;
	return ;
}

/**
 * @brief Décale d’une position vers le bas tous les élements de la pile a.
 * 		  Le dernier élément devient le premier.
 */
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

/**
 * @brief Décale d’une position vers le bas tous les élements de la pile b.
 * 		  Le dernier élément devient le premier.
 */
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

/**
 * @brief rra et rrb en même temps.
 */
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
