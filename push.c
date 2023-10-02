/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:49 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:35:52 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*third_last;

	if (stacklen(*stack_src) == 0)
		ft_putendl_fd("No value in source stack", 1);
	new_last_node(stack_dest, last_node(*stack_src));
	if (stacklen(*stack_src) == 1)
		*stack_src = NULL;
	else
	{
		third_last = *stack_src;
		while (third_last->p->p)
			third_last = third_last->p;
		third_last->p = NULL;
	}
}

// Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

// Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
