/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:23 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 15:23:24 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Alloue de la mémoire pour un nouveau nœud "node" de type t_stack.
// Vérifie l'allocation puis initialise les différents champs
// du nœud.
static t_stack	*node_init(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->nbr = content;
	node->i = -1;
	node->p = NULL;
	return (node);
}

// Calcule le nombre d'arguments si l'arg n'est pas passe entre guillemets.
int	nb_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[i] != 0)
		i++;
	return (i);
}

// node va pointer vers le 1e noeud non indexe de la liste
// min pointe vers le nœud avec la plus petite valeur qui n'a pas
// encore été indexé.
// La fonction renvoie le pointeur vers le nœud non indexé ayant la plus
// petite valeur.
static t_stack	*index_init(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*min;

	node = *stack_a;
	while (node && node->i != -1)
		node = node->p;
	min = node;
	while (node)
	{
		if (node->i == -1 && node->nbr < min->nbr)
			min = node;
		node = node->p;
	}
	return (min);
}

// Crée un nouveau nœud pour chaque argument avec la fonction "node_init"
// et y met la valeur de l'argument passé en int.
// Le pointeur de la struct new pointe alors vers l'ancien élément
// ajouté à la pile.
// Puis la valeur de new est à son tour ajoutée à la pile.
// Enfin les noeuds sont indexes 1 a 1 dans l'ordre croissant de leurs
//valeurs.
void	stack_init(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
	int		i;

	i = 1; // si sans guillemets
	if (argc == 2)
		i = 0; // si guillemets
	while (argv[i])
	{
		new = node_init(ft_atoi(argv[i]));
		if (!new)
			return ;
		new->p = (*stack_a);
		(*stack_a) = new;
		i++;
	}
	i = 0;
	while (i < (int []){argc - 1, nb_arg(argc, argv)}[(argc == 2)])
	{
		new = index_init(stack_a);
		new->i = i++;
	}
}
