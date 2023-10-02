/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:31 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 16:07:42 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free chaque noeud de la pile a.
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

// Verifie qu'il y ait une pile a.
int	checkemptystack(t_stack **stack)
{
	if (!*stack)
		return (1);
	else
		return (0);
}

// Avance dans les noeuds jusqu'a atteindre le dernier et le renvoie.
t_stack	*last_node(t_stack *stack)
{
	while (stack->p)
		stack = stack->p;
	return (stack);
}

// Ajoute un nouveau noeud a la fin d'une pile.
// Si la pile est vide, new_node devient le 1er et unique element.
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
