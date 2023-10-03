/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:26 by nessie            #+#    #+#             */
/*   Updated: 2023/10/03 19:36:20 by nessie           ###   ########.fr       */
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

/**
 * @brief Fonction qui dirige les différentes stacks vers les fonctions de tri
 * 		  en fonction du nombre d'arguments.
 * 		  stacklen: calcule la taille de la stack A.
 * 		  checkbackwards: vérifie que la stack A ne soit pas triée à l'envers.
 */
void	sort_a(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	if (len <= 1)
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
