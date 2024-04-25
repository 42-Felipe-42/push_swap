/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:19:36 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:58:58 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		pile_a = split_arg(av, &pile_a);
	if (!pile_a && ac > 2)
		pile_a = init_stack(av, ac, &pile_a);
	if (!is_sorted(pile_a))
	{
		if (ft_listsize(pile_a) == 2)
			sa(&pile_a, 1);
		else if (ft_listsize(pile_a) == 3)
			for_three(&pile_a);
		else
			sort_arg(&pile_a, &pile_b);
	}
	ft_free_stack (&pile_a);
	return (0);
}
