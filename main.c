/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:14:39 by acatusse          #+#    #+#             */
/*   Updated: 2023/10/02 16:09:08 by acatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free les chaînes du tableau pour éviter les leaks potentiels causés par
// "ft_split" dans la fonction "ft_error".
static void	clean_string(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	while (i--)
		free(argv[i]);
}

// On crée 2 piles initialisées à Null, fill la A avec "stack_init" et trie
// son contenu avec "sort".
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_error(argc, &argv))
	{
		if (argc == 2)
		{
			clean_string(argv);
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
		clean_string(argv);
		free(argv);
	}
	clean_stack(&stack_a);
	return (0);
}
