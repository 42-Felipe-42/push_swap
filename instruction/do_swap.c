/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:00:03 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:22:48 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_swap(t_stack **head)
{
	t_stack	*temp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void	sa(t_stack **pile_a, int print)
{
	make_swap(pile_a);
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **pile_b, int print)
{
	make_swap(pile_b);
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **pile_a, t_stack **pile_b, int print)
{
	sa(pile_a, 0);
	sb(pile_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}
