/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nessie <nessie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:12:16 by nessie            #+#    #+#             */
/*   Updated: 2023/10/03 17:29:22 by nessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
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

int	check_range(char *str)
{
	char	*ult_int;
	int		i;
	int		j;

	ult_int = "-2147483647";
	i = 0;
	j = 0;
	if (ft_strlen(str) > 11)
		return (1);
	else if (ft_strlen(str) < 10 || ft_strncmp(str, "-2147483648", 11) == 0
		|| (str[0] == '-' && ft_strlen(str) == 10))
		return (0);
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

int	check_double(char **argv, int nb, int i)
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

/**
 * @brief Fonction erreur: Si deux arguments, utilise ft_split pour diviser
 * 	  l'arg en tableau de chaînes a chaque présence d'espace.
 * 	  La fonction vérifie si chaque chaîne est conforme à ce qui est
 * 	  attendu:
 * 		- Si elle est bien uniquement composée de chiffres
 * 		- Si sa valeur est bien comprise entre INT_MIN et INT_MAX 
 * 		- Si le tableau ne comprend pas deux chaînes identiques
 * 
 * @return Si une erreur est trouvée :"Error" sur la sortie 2, sortie d'erreur
 * 	   comme demandé dans le sujet.
 * 	   Sinon (1).
 */
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
