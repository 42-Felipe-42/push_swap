/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:00:08 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:19:58 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_push(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	if (!(*head_a))
		return ;
	temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = *head_b;
	*head_b = temp;
}

void	pa(t_stack **head_b, t_stack **head_a, int print)
{
	make_push(head_b, head_a);
	if (print == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **head_a, t_stack **head_b, int print)
{
	make_push(head_a, head_b);
	if (print == 1)
		ft_printf("pb\n");
}
