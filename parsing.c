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

// Check que la chaîne soit dans la range traitée par le type int.
// str > 11, forcément out of range
// < 10 / égal à INT_MIN / négatif et len=10 forcément dans la range.
// Si aucun des cas précédents, on compare chiffre par chiffre et si str >
// ult_int, alors forcément out of range.
static int	check_range(char *str)
{
	int		i;
	int		j;
	char	*ult_int;

	if (ft_strlen(str) > 11)
		return (1);
	else if (ft_strlen(str) < 10 || ft_strncmp(str, "-2147483648", 11) == 0
		|| (str[0] == '-' && ft_strlen(str) == 10))
		return (0);
	i = 0;
	j = 0;
	ult_int = "-2147483647";
	if (str[0] != '-')
		j = 1;
	while (str[i] != '\0')
	{
		if (str[i] > ult_int[j])
			return (1);
		j++;
		i++;
	}
	return (0);
}

// Nb est la string actuellement traitée par ft_error, et argv[i] est la
// string suivante dans le tableau. On incrémente i tant qu'aucune string ne
// correspond à nb.
static int	check_double(char **argv, int nb, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

// Transforme av en tableau de chaînes grâce à "ft_split" si ac==2 
// et/ou vérifie à l'aide des fonctions check_* que chaque chaîne du 
// tableau ne comporte pas d'erreur.
int	ft_error(int argc, char ***argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (!(*argv))
			return (0);
		i = 0;
	}
	while ((*argv)[i])
	{
		if (!check_digit((*argv)[i]) || check_range((*argv)[i]) || \
			check_double((*argv), ft_atoi((*argv)[i]), i))
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
