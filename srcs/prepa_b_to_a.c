/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepa_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:27:28 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:20 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Trouve la cible de 'b'-> 'a' en cherchant la valeur la plus grande proche,
//si elle ne trouve pas cette valeur pointe vers la valeur min
void	target_node_ba(t_stack *pile_a, t_stack *pile_b)
{
	t_stack	*a;
	t_stack	*target_node;
	int		best_target;

	target_node = NULL;
	while (pile_b)
	{
		best_target = INT_MAX;
		a = pile_a;
		while (a)
		{
			if (a->content > pile_b->content && a->content < best_target)
			{
				best_target = a->content;
				target_node = a;
			}
			a = a->next;
		}
		if (best_target == INT_MAX)
			pile_b->target_node = find_min(pile_a);
		else
			pile_b->target_node = target_node;
	pile_b = pile_b->next;
	}
}

//Initialisation de la pile avec tout les elements requis
void	init_stack_ba(t_stack *pile_b, t_stack *pile_a)
{
	find_index(pile_a);
	find_index(pile_b);
	target_node_ba(pile_a, pile_b);
}

//Prepare la pile_a avant de push de b->a en remontant la cible de 'a' au top
void	move_b_to_a(t_stack **pile_a, t_stack **pile_b)
{
	move_before_push(pile_a, (*pile_b)->target_node, 1);
	pa(pile_b, pile_a, 1);
}
