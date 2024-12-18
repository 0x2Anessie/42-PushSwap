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
 */
void	sort_a(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	if (len <= 1 || already_sorted(a))
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
