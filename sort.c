/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:26 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:31:21 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp != 0)
	{
		tmp = tmp->p;
		len++;
	}
	return (len);
}

// Verifie si la pile est deja triee dans l'ordre decroissant
// Pour chaque noeud elle verifie que sa valeur soit inferieure a la
// valeur du noeud suivant.
int	checkbackwards(t_stack **a)
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

// Une fois qu'on a le nombre d'elements dans la pile, et qu'on a check les
// erreurs comme un seul arg ou si la pile est triee par ordre decroissant.
// En foction du nombre d'arguments, la pile a trier est envoyee dans
// les differentes fonctions de tri.
void	sort_a(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	if (len <= 1 || checkbackwards(a))
		return ;
	else if (len == 2)
		sa(a);
	else if (len == 3)
		three_values(a);
	else if (len == 4)
		four_values(a, b);
	else if (len == 5)
		five_values(a, b);
	else
		radix(a, b);
}
