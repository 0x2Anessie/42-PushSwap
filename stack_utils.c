#include "push_swap.h"

/**
 * @brief Free chaque noeud de la stack A.
 */
void	clean_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*stack;

	stack = *a;
	while (stack != 0)
	{
		tmp = stack->p;
		free(stack);
		stack = tmp;
	}
}

/**
 * @brief Vérifie qu'il y ait une stack A.
 */
int	checkemptystack(t_stack **stack)
{
	if (!*stack)
		return (1);
	else
		return (0);
}

/**
 * @brief Avance dans les noeuds jusqu'a atteindre le dernier et le renvoie.
 */
t_stack	*last_node(t_stack *stack)
{
	while (stack->p)
		stack = stack->p;
	return (stack);
}

/**
 * @brief Ajoute un nouveau noeud à la fin d'une stack (le début du coup).
 *        Si la stack est vide, new_node devient le 1er et unique élément.
 */
void	new_last_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (new_node)
	{
		if (!*stack)
		{
			*stack = new_node;
			return ;
		}
		last = last_node(*stack);
		last->p = new_node;
	}
}

/**
 * @brief Vérifie que la stack A ne soit pas triée par orde décroissant.
 */
int	already_sorted(t_stack **a)
{
	t_stack	*stack;

	stack = *a;
	while (stack->p)
	{
		if (stack->nbr < stack->p->nbr)
			return (0);
		stack = stack->p;
	}
	return (1);
}
