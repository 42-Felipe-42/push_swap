/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:50:10 by plangloi          #+#    #+#             */
/*   Updated: 2024/03/27 14:19:13 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Verifie si la valeur depasse le int max ou le min
int	check_int(char *av)
{
	int		len;
	long	value;
	int		i;

	i = 0;
	while (av[i] == '0')
		i++;
	len = ft_strlen(&av[i]);
	if (len > 11)
		return (0);
	value = ft_atol(av);
	if (value < INT_MIN)
		return (0);
	if (value > INT_MAX)
		return (0);
	return (1);
}

//Permet de savoir si il y a un signe dans la valeur
int	ft_check_sign(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		return (1);
	return (0);
}

//Verifie si la valeur est un chiffre en ignorant les signes '-' et '+'
int	ft_check_is_number(char *arg)
{
	int	i;

	i = 0;
	if (ft_check_sign(arg) && arg[i +1])
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] && !ft_isdigit(arg[i]))
		return (0);
	return (1);
}

/* Verifie si les parametres sont bien un chiffre,
les doublons et que ca ne depasse pas le int max et min */
int	ft_check_input(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		if (!ft_check_is_number(arg[i]))
			return (0);
		if (!check_int(arg[i]))
			return (0);
		while (arg[j])
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}
