/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:23 by nessie            #+#    #+#             */
/*   Updated: 2023/10/04 12:24:06 by nessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	nb_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[i] != 0)
		i++;
	return (i);
}

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

/**
 * @brief Fonction qui initialise de nouveaux noeuds pour chaque valeur passées
 * 		  en argument.
 * 		  Une fois crées elle les ajoute à la stack A et leur donne pour index
 * 		  leur position dans un ordre croissant. Elles seront ensuite triées 
 * 		  par le reste du programme grace à cet index.
 * 		  node_init: alloue de la mémoire pour un nouveau noeud, donne la
 * 				     valeur de l'argument change en int a l'élement nbr et 
 * 				     initialise les autres éléments du noeud a nul.
 * 		  index_init: trouve un noeud pas encore indexé et le stock dans min.
 * 					  la fonction parcours alors la stack A et si un noeud non
 * 					  indexé a un element nbr plus petit que min, il devient
 * 					  le nouveau min est est return.
 */
void	stack_init(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
	int		i;

	i = 1;
	if (argc == 2)
		i = 0;
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
