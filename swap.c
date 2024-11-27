#include "push_swap.h"

/**
 * @brief Intervertit les deux premiers éléments au sommet d'une stack.
 * 		  Soit deux elements, donc on echange leur p.
 * 		  Soit +, donc le 3e (bbl) prend le 1e (l) en p, et le 1e (l) prend le
 * 		  2e (bl), et le 2e (bl) prend NULL.
 */
void	swap(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;
	t_stack	*b_b_last;

	if (stacklen(*stack) <= 1)
		ft_putendl_fd("Stack is empty or has only one element", 1);
	if (stacklen(*stack) == 2)
	{
		last = last_node(*stack);
		last->p = *stack;
		(*stack)->p = NULL;
		*stack = last;
	}
	else
	{
		b_b_last = *stack;
		while (b_b_last->p->p->p)
			b_b_last = b_b_last->p;
		before_last = b_b_last->p;
		last = before_last->p;
		b_b_last->p = last;
		last->p = before_last;
		before_last->p = NULL;
	}
}

/**
 * @brief Intervertit les 2 premiers éléments au sommet de la pile a.
 */
void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

/**
 * @brief Intervertit les 2 premiers éléments au sommet de la pile b.
 */
void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

/**
 * @brief sa et sb en même temps.
 */
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
