/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:39 by nessie            #+#    #+#             */
/*   Updated: 2023/10/03 12:24:18 by nessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_strings(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	while (i--)
		free(argv[i]);
}

/**
 * @brief: Fonction main: Vérifie qu'il n'y ait pas d'erreurs dans la/les
 * 	   chaînes passées en arg. Elle crée deux stack, les set a NULL puis
 * 	   initialise la stack A avec stack_init. 
 * 	   Le tri de la stack A s'effectura dans la fonction sort_a.
 * 
 * @warning: Pour éviter les fuites de mémoire, penser à clean le tableau (free)
 * 	     et les chaînes qui le composent (clean_strings) quand argv == 2 car
 * 	     la fonction ft_error utilise malloc dans ce cas là.
 * 	     clean_stack: free les noeuds de la liste chaînée stack A.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_error(argc, &argv))
	{
		if (argc == 2)
		{
			clean_strings(argv);
			free(argv);
		}
		return (0);
	}
	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argc, argv);
	sort_a(&stack_a, &stack_b);
	if (argc == 2)
	{
		clean_strings(argv);
		free(argv);
	}
	clean_stack(&stack_a);
	return (0);
}
