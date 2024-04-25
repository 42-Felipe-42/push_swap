/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:54:51 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:20:38 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_reverse_rotate(t_stack **pile)
{
	t_stack	*end;
	t_stack	*temp;

	temp = NULL;
	end = NULL;
	if (!(*pile) || (*pile)->next == NULL)
		return ;
	temp = *pile;
	while (temp->next != NULL)
	{
		end = temp;
		temp = temp->next;
	}
	end->next = NULL;
	temp->next = *pile;
	*pile = temp;
}

void	rra(t_stack **pile_a, int print)
{
	make_reverse_rotate(pile_a);
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **pile_b, int print)
{
	make_reverse_rotate(pile_b);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **pile_a, t_stack **pile_b, int print)
{
	rra(pile_a, 1);
	rrb(pile_b, 1);
	if (print == 1)
		ft_printf("rrr\n");
}

void	rrr_cheapest_top(t_stack **pile_a, t_stack **pile_b,
						t_stack *cheapest_node)
{
	while (*pile_b != cheapest_node->target_node
		&& *pile_a != cheapest_node)
		rr(pile_a, pile_b, 1);
	find_index(*pile_a);
	find_index(*pile_b);
}
