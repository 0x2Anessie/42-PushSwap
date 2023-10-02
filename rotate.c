/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:18 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:39:01 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*third_last;
	t_stack	*last;

	if (stacklen(*stack) <= 1)
		ft_putendl_fd("Stack is empty or has only one element", 1);
	third_last = *stack;
	while (third_last->p->p)
		third_last = third_last->p;
	last = third_last->p;
	third_last->p = NULL;
	last->p = *stack;
	*stack = last;
}

// Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

// Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

// ra et rb en même temps.
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
