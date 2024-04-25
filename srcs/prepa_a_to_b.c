/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepa_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:29:42 by plangloi          #+#    #+#             */
/*   Updated: 2024/04/22 16:45:47 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Trouve la cible de 'a'-> 'b' en cherchant la valeur la plus petite proche,
//si elle ne trouve pas cette valeur pointe vers la valeur maximum
void	target_node_ab(t_stack *pile_a, t_stack *pile_b)
{
	t_stack	*target_node;
	t_stack	*b;
	int		best_target;

	target_node = NULL;
	while (pile_a)
	{
	b = pile_b;
	best_target = INT_MIN;
		while (b)
		{
			if (b->content < pile_a->content && b->content > best_target)
			{
			best_target = b->content;
			target_node = b;
			}
			b = b->next;
		}
		if (best_target == INT_MIN)
			pile_a->target_node = find_max(pile_b);
		else
			pile_a->target_node = target_node;
	pile_a = pile_a->next;
	}
}

//Permet de calculer le cout selon la position de l'index
void	cost_ab(t_stack *pile_a, t_stack *pile_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_listsize(pile_a);
	size_b = ft_listsize(pile_b);
	while (pile_a)
	{
		pile_a->cost = pile_a->index;
		if (pile_a->above_median && pile_a->target_node->above_median)
			pile_a->cost += pile_a->index + pile_a->target_node->index;
			
		if ((pile_a->above_median) && !(pile_a->target_node->above_median))
			pile_a->cost += pile_a->index + (size_b - pile_a->target_node->index);
			
		if (!(pile_a->above_median) && !(pile_a->target_node->above_median))
			pile_a->cost += (size_a - pile_a->target_node->index) + (size_b - pile_a->target_node->index);
			
		if (!(pile_a->above_median) && (pile_a->target_node->index))
			pile_a->cost += (size_a - pile_a->index) + pile_a->target_node->index;
	pile_a = pile_a->next;
	}
}

//Initialisation de la pile avec tout les elements requis
void	init_stack_ab(t_stack *pile_a, t_stack *pile_b)

{
	find_index(pile_a);
	find_index(pile_b);
	target_node_ab(pile_a, pile_b);
	cost_ab(pile_a, pile_b);
	define_cheapest(pile_a);
}

//Preparation de la pile 'a' pour push vers 'b' en remontant
//le cheapest de 'a' et la target de 'b'
void	move_a_to_b(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*pile_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rr_cheapest_top(pile_a, pile_b, cheapest_node);
	if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rrr_cheapest_top(pile_a, pile_b, cheapest_node);
	move_before_push(pile_a, cheapest_node, 1);
	move_before_push(pile_b, cheapest_node->target_node, 2);
	if (ft_listsize(*pile_a) > 3 && !(is_sorted(*pile_a)))
		pb(pile_a, pile_b, 1);
}
