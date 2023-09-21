#include "push_swap.h"

// Check que la chaîne ne soit composés que de chiffres (0-9)
static int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str && str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Check que la chaîne soit dans la range traitée par le type int
static int	check_range(char *str)
{
	int		i;
	int		j;
	char	*ultmax;

	if (ft_strlen(str) > 11) // Forcément out of range
		return (1);
	else if (ft_strlen(str) < 10 || ft_strncmp(str, "-2147483648", 11) == 0
		|| (str[0] == '-' && ft_strlen(str) == 10)) // Forcément dans la range
		return (0);
	i = 0;
	j = 0;
	ultmax = "-2147483647";
	if (str[0] != '-')
		j = 1;
	while (str[i] != '\0')
	{
		if (str[i] > ultmax[j]) // Si str[i] > ultmax[j] alors > INT_MAX
			return (1);
		j++;
		i++;
	}
	return (0);
}

// Check qu'il n'y a pas de digit en double dans les chaines du tab
static int	check_double(char **argv, int nb, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb) // i comparé avec nb ((*argv)[i] - 1)
			return (1);
		i++;
	}
	return (0);
}

// Transforme argv en tableau de chaînes et vérifie a l'aide des fonctions
// check que chaque chaîne du tableau ne comporte pas d'erreur.
int	ft_error(int argc, char ***argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		*argv = ft_split((*argv)[1], ' '); // Crée un tableau de chaînes
		if (!(*argv))
			return (0);
		i = 0;
	}
	while ((*argv)[i])
	{
		if (!check_digit((*argv)[i]) || check_range((*argv)[i]) || \
			check_double((*argv), ft_atoi((*argv)[i]), i))
		{
			ft_putendl_fd("Error", 2); // Si une des erreurs est trouvée
			return (0);
		}
		i++;
	}
	return (1);
}
