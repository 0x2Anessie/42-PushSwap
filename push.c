#include "push_swap.h"

/**
 * @brief Push le premier element d'une stack sur l'autre.
 * 		  Si rien dans la stack source, print message d'erreur.
 * 		  Cree le nouveau noeud avec new_last_node.
 * 		  Puis on supprime le p de l'avant dernier.
 */
void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*first_node;

	if (stacklen(*stack_src) == 0)
		ft_putendl_fd("No value in source stack", 1);
	new_last_node(stack_dest, last_node(*stack_src));
	if (stacklen(*stack_src) == 1)
		*stack_src = NULL;
	else
	{
		first_node = *stack_src;
		while (first_node->p->p)
			first_node = first_node->p;
		first_node->p = NULL;
	}
}

/**
 * @brief Prend le premier élément au sommet de B et le met sur A.
 * 		  Ne fait rien si b est vide.
 */
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

/**
 * @brief Prend le premier élément au sommet de A et le met sur B.
 * 		  Ne fait rien si a est vide.
 */
void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
