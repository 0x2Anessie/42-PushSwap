#include "push_swap.h"

// Free les chaînes du tableau pour éviter les leaks potentiels causés par
// "ft_split" dans la fonction "ft_error".
static void	clean_strings(char **argv)
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
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!ft_error(argc, &argv))
	{
		if (argc == 2)
		{
			clean_strings(argv);
			free(argv);
		}
		return (0);
	}
	stack_init(&a, argc, argv);
	sort_a(&a, &b);
	if (argc == 2)
	{
		clean_strings(argv);
		free(argv);
	}
	clean_stack(&a);
	return (0);
}
