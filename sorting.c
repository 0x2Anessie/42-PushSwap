/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:12:39 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:58:11 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verfie les 5 cas de figure possible.
// "3 2 1"  /  "2 3 1"  /  "3 1 2"  /  "1 3 2"  /  "2 1 3"
void	three_values(t_stack **a)
{
	if ((*a)->i < (*a)->p->i && (*a)->p->i < (*a)-> \
			p->p->i && (*a)->p->p->i > (*a)->i)
	{
		ra(a);
		sa(a);
	}
	if ((*a)->i < (*a)->p->i && (*a)->p->i > (*a)-> \
			p->p->i && (*a)->p->p->i > (*a)->i)
		rra(a);
	if ((*a)->i > (*a)->p->i && (*a)->p->i < (*a)-> \
			p->p->i && (*a)->p->p->i > (*a)->i)
		ra(a);
	if ((*a)->i < (*a)->p->i && (*a)->p->i > (*a)-> \
			p->p->i && (*a)->p->p->i < (*a)->i)
	{
		rra(a);
		sa(a);
	}
	if ((*a)->i > (*a)->p->i && (*a)->p->i < (*a)-> \
			p->p->i && (*a)->p->p->i < (*a)->i)
		sa(a);
}

// Trouve l'element avec le plus petit indice car min indice = min value
// grace a index_init.
// Met cet element en haut de la pile a puis le push sur la pile b.
// On trie la pile a et on renvoie le minus au sommet de la pile a
void	four_values(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->i == 0)
			break ;
		i++;
		tmp = tmp->p;
	}
	if (i == 0)
		rra(a);
	if (i == 1)
		ra(a);
	if (i == 2 || i == 1)
		sa(a);
	pb(b, a);
	three_values(a);
	pa(a, b);
}

// Trouve l'indice 1 et le bouge pour trier les 3 restants, puis le remet.
static void	five__values_utils(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->i == 1)
			break ;
		i++;
		tmp = tmp->p;
	}
	if (i == 0)
		rra(a);
	if (i == 1)
		ra(a);
	if (i == 2 || i == 1)
		sa(a);
	pb(b, a);
	three_values(a);
	pa(a, b);
}

// Trouve l'element avec le plus petit indice car min indice = min value
// grace a index_init.
// Met cet element en haut de la pile a puis le push sur la pile b.
// Utilise la fonction fourorfive pour mettre l'indice 1 dans la pile b aussi,
// trie les 3 restants avec tree, remet l'indice 1.
// Remet l'indice 0 dans la pile a.
void	five_values(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->i == 0)
			break ;
		i++;
		tmp = tmp->p;
	}
	if (i == 0 || i == 1)
		rra(a);
	if (i == 1)
		rra(a);
	if (i == 2)
		ra(a);
	if (i == 2 || i == 3)
		sa(a);
	pb(b, a);
	five__values_utils(a, b);
	pa(a, b);
}

// Tant que la pile a n'est pas triee, 
void	radix(t_stack **a, t_stack **b)
{
	t_stack	*stack;
	int		len_a;
	int		bit;
	int		index;

	len_a = stacklen(*a);
	bit = 0;
	while (!checkbackwards(a))
	{
		stack = *a;
		index = 0;
		while (index < len_a && stack && !checkbackwards(a))
		{
			if ((last_node(*a)->i >> bit) & 1)
				ra(a);
			else
				pb(b, a);
			index++;
		}
		while (!checkemptystack(b))
			pa(a, b);
		bit++;
	}
}
