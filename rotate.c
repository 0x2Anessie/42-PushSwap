#include "push_swap.h"

/**
 * @brief Fonction qui avance chaque element de la stack d'une position.
 * 		  Le premier devient sont le dernier.
 * 		  le deuxieme (bl) devient 1e et pointe sur la suite de la liste,
 * 		  et le 1e (l) devient dernier et pointe sur null.
 */
void	rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (stacklen(*stack) <= 1)
		ft_putendl_fd("Stack is empty or has only one element", 1);
	before_last = *stack;
	while (before_last->p->p)
		before_last = before_last->p;
	last = before_last->p;
	before_last->p = NULL;
	last->p = *stack;
	*stack = last;
}

/**
 * @brief Décale d’une position vers le haut tous les élements de la stack A.
 * 		  Le premier élément devient le dernier.
 */
void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

/**
 * @brief Décale d’une position vers le haut tous les élements de la stack B.
 *        Le premier élément devient le dernier.
 */
void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

/**
 * @brief ra et rb en même temps.
 */
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
