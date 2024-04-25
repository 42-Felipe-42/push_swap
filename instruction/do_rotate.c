/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:59:47 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:44 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_rotate(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*start;

	start = NULL;
	temp = NULL;
	if (!(*pile) || (*pile)->next == NULL)
		return ;
	temp = *pile;
	start = *pile;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = start;
	*pile = start->next;
	start->next = NULL;
}

void	ra(t_stack **pile_a, int print)
{
	make_rotate(pile_a);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **pile_b, int print)
{
	make_rotate(pile_b);
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **pile_a, t_stack **pile_b, int print)
{
	ra(pile_a, 0);
	rb(pile_b, 0);
	if (print == 1)
		ft_printf("rr\n");
}

void	rr_cheapest_top(t_stack **pile_a, t_stack **pile_b,
					t_stack *cheapest_node)
{
	while (*pile_b != cheapest_node->target_node && *pile_a != cheapest_node)
		rr(pile_a, pile_b, 1);
	find_index(*pile_a);
	find_index(*pile_b);
}
