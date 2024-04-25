/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:58:40 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:33 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Mettre la valeur min au top de 'a' selon si il est 
//en dessous ou au dessus de la mediane
void	min_on_top(t_stack **pile_a)
{
	while ((*pile_a)->content != find_min(*pile_a)->content)
	{
		if (find_min(*pile_a)->above_median)
			ra(pile_a, 1);
		else
			rra(pile_a, 1);
	}
}

//Permet de trouver l'index et de savoir si cette index est 
//au dessus ou en dessous de la median en mettant un flag
void	find_index(t_stack *pile_a)
{
	int	median;
	int	i;

	i = 0;
	median = ft_listsize(pile_a) / 2;
	if (!pile_a)
		return ;
	while (pile_a)
	{
		pile_a->index = i;
		if (i <= median)
			pile_a->above_median = true;
		else
			pile_a->above_median = false;
		pile_a = pile_a->next;
	i++;
	}
}

//Permet de deplacer la valeur au top de 'a' ou de 'b' selon le flag 
void	move_before_push(t_stack **pile, t_stack *top_node,
		int pile_name)
{
	while (*pile != top_node)
	{
		if (pile_name == 1)
		{
			if (top_node->above_median)
				ra(pile, 1);
			else
				rra(pile, 1);
		}
		else if (pile_name == 2)
		{
			if (top_node->above_median)
				rb(pile, 1);
			else
				rrb(pile, 1);
		}
	}
}

//Definie qu'elle est la node au coup le moin chere, et la flag avec un bool
void	define_cheapest(t_stack *pile_a)
{
	t_stack	*cheapest_node;
	int		cheapest_value;

	cheapest_value = INT_MAX;
	while (pile_a)
	{
		if (pile_a->cost < cheapest_value)
		{
			cheapest_value = pile_a->cost;
			cheapest_node = pile_a;
		}
		pile_a = pile_a->next;
	}
	cheapest_node->cheapest = true;
}

//Permet de verifier si la valeur de la pile est la cheapest value qui est flag
t_stack	*get_cheapest(t_stack *pile)
{
	if (!pile)
		return (NULL);
	while (pile)
	{
		if (pile->cheapest)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}
