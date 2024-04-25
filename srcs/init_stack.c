/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:28:00 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 16:35:38 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Initialise la pile en verifiant si les arguments sont valides
t_stack	*init_stack(char **av, int ac, t_stack **lsta)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (ft_check_input(av +1) != 1)
		return (write(2, "Error\n", 6), NULL);
	if (!*lsta)
	{
		if (av[i][0] == '\0')
			return (write(2, "Error\n", 6), NULL);
		(*lsta = ft_lstnew_int(ft_atol(av[i])), i++);
		if (!*lsta)
			return (NULL);
	}
	tmp = *lsta;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (write(2, "Error\n", 6), NULL);
		tmp->next = ft_lstnew_int(ft_atol(av[i]));
		if (!(tmp->next))
			return (NULL);
		(tmp = tmp->next, i++);
	}
	return (*lsta);
}

t_stack	*split_arg(char **av, t_stack **pile)
{
	char	**split_res;
	int		i;
	t_stack	*tmp;

	i = 0;
	split_res = ft_split(av[1], ' ');
	if (!split_res[0])
		return (write(2, "Error\n", 6), free_split(split_res), NULL);
	if (ft_check_input(split_res) != 1)
		return (write(2, "Error\n", 6), free_split(split_res), NULL);
	if (!*pile)
	{
		(*pile = ft_lstnew_int(ft_atol(split_res[i])), i++);
		if (!*pile)
			return (free_split(split_res), NULL);
	}
	tmp = *pile;
	while (split_res[i])
	{
		tmp->next = ft_lstnew_int(ft_atol(split_res[i]));
		if (!(tmp->next))
			return (NULL);
		(tmp = tmp->next, i++);
	}
	return (free_split(split_res), *pile);
}

//Permet de verifier si la pile est trie ou non
int	is_sorted(t_stack *pile_a)
{
	t_stack	*temp;

	temp = pile_a;
	if (ft_listsize(pile_a) > 1)
	{
		while (temp->next)
		{
			if (temp->content > temp->next->content)
				return (0);
		temp = temp->next;
		}
	}
	return (1);
}
