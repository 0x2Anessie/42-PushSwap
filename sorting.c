/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:12:39 by nessie            #+#    #+#             */
/*   Updated: 2023/10/04 18:47:38 by nessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Verifie les 5 cas possibles.
 * 		  3 2 1"  /  "2 3 1"  /  "3 1 2"  /  "1 3 2"  /  "2 1 3"
 */
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

/**
 * @brief Trouve le plus petit indice, le met en haut de la stack A
 * 		  puis le push sur la stack B.
 * 		  La pile est triée avec three_values, puis le plus petit indice
 * 		  est push en haut de a stack A.
 */
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

/**
 * @brief Même brief que pour four_values mais push sur la stack B la DEUXIEME
 * 		  plus petite valeur.
 */
static void	five_values_utils(t_stack **a, t_stack **b)
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

/**
 * @brief Fonctionne comme four_values mais utilise five_values_utils pour
 * 		  trier les 4 int restants.
 */
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
	five_values_utils(a, b);
	pa(a, b);
}

/**
 * @brief Méthode de tri bit par bit en commencant par le LSB.
 * 		  Le tri s'execute tant que la stack A n'est pas completement triée.
 * 		  	Tant que tous les éléments n'ont pas été traités, on vérrifie le
 * 		  	bit en cours du dernier élément de la pile.
 * 		  		Si ce bit est égal à 1, on rotate la stack A.
 * 		  		Si ce bit est égal à 0, on push son élément sur la stack B.
 * 			Ensuite on vide la stack B dans la stack A et on incrémente bit
 * 			pour recommencer tout ce processus avec le prochain LSB.
 * 
 * @var LEN: contient la taille de la stack A.
 * @var BIT: détermine quel bit on va regarder pour trier, init a 0 pour
 * 			 commencer par le LSB.
 * @var STACK: sert à se balader dans la stack A.
 */
void	radix(t_stack **a, t_stack **b)
{
	t_stack	*stack;
	int		i;
	int		len_a;
	int		bit;

	len_a = stacklen(*a);
	bit = 0;
	while (!already_sorted(a))
	{
		stack = *a;
		i = 0;
		while (i < len_a && stack)
		{
			if ((last_node(*a)->i >> bit) & 1)
				ra(a);
			else
				pb(b, a);
			i++;
		}
		while (!checkemptystack(b))
			pa(a, b);
		bit++;
	}
}
