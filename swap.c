/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:34 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:34:21 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*third_last;
	t_stack	*last;

	if (stacklen(*stack) <= 1)
		ft_putendl_fd("Stack is empty or has only one element", 1);
	if (stacklen(*stack) == 2)
	{
		last = last_node(*stack);
		last->p = *stack;
		(*stack)->p = 0;
		*stack = last;
	}
	else
	{
		second_last = *stack;
		while (second_last->p->p->p)
			second_last = second_last->p;
		third_last = second_last->p;
		last = third_last->p;
		second_last->p = last;
		last->p = third_last;
		third_last->p = 0;
	}
}

// Intervertit les 2 premiers éléments au sommet de la pile a.
void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

// Intervertit les 2 premiers éléments au sommet de la pile b.
void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

// sa et sb en même temps.
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
