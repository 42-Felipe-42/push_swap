/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:28:51 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:52:36 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//trouve la valeur min dans la pile
t_stack	*find_min(t_stack *pile_a)
{
	long	lowest_value;
	t_stack	*temp;

	if (!pile_a)
		return (NULL);
	lowest_value = LONG_MAX;
	while (pile_a)
	{
		if (pile_a->content < lowest_value)
		{
			lowest_value = pile_a->content;
			temp = pile_a;
		}
	pile_a = pile_a->next;
	}
	return (temp);
}	

//Trouve la valeur max dans la pile
t_stack	*find_max(t_stack *pile_a)
{
	long	greatest_value;
	t_stack	*temp;

	temp = NULL;
	if (!pile_a)
		return (NULL);
	greatest_value = LONG_MIN;
	while (pile_a)
	{
		if (pile_a->content > greatest_value)
		{
			greatest_value = pile_a->content;
			temp = pile_a;
		}
	pile_a = pile_a->next;
	}
	return (temp);
}	

// Trie pour 3 elements
t_stack	*for_three(t_stack **pile_a)
{
	int	av1;
	int	av2;
	int	av3;

	av1 = (*pile_a)->content;
	av2 = (*pile_a)->next->content;
	av3 = (*pile_a)->next->next->content;
	if (pile_a != NULL && (*pile_a)->next != NULL)
	{
		if (av1 < av2 && av2 > av3 && av3 < av1)
			return (rra(pile_a, 1), *pile_a);
		if (av1 > av2 && av2 < av3 && av3 > av1)
			return (sa(pile_a, 1), *pile_a);
		if (av1 < av2 && av2 > av3 && av3 > av1)
			return (sa(pile_a, 1), ra(pile_a, 1), *pile_a);
		if (av1 > av2 && av2 > av3 && av1 > av3)
			return (ra(pile_a, 1), sa(pile_a, 1), *pile_a);
		if (av1 > av2 && av2 < av3 && av3 < av1)
			return (ra(pile_a, 1), *pile_a);
	}
	return (*pile_a);
}

//Push les 2 premiers elements de a->b pour ensuite push a->b 
//selon sa cible dans 'b' jusqu'a que a = 3 elements
//et ensuite push b->a selon sa cible dans 'a' jusqu'a que b soit vide  
void	sort_arg(t_stack **pile_a, t_stack **pile_b)
{
	int	len;

	len = ft_listsize(*pile_a);
	if (len-- > 3 && !(is_sorted(*pile_a)))
		pb(pile_a, pile_b, 1);
	if (len-- > 3 && !(is_sorted(*pile_a)))
		pb(pile_a, pile_b, 1);
	while (len > 3 && !(is_sorted(*pile_a)))
	{
		init_stack_ab(*pile_a, *pile_b);
		move_a_to_b(pile_a, pile_b);
		len--;
	}
	for_three(pile_a);
	while (*pile_b)
	{
		init_stack_ba(*pile_b, *pile_a);
		move_b_to_a(pile_a, pile_b);
	}
	find_index(*pile_a);
	min_on_top(pile_a);
}
