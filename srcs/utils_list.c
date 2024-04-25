/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:55:28 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 15:49:55 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Permet de retourner la taille de la pile
int	ft_listsize(t_stack *lst)
{
	int	lstlen;

	lstlen = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		lstlen++;
	}
	return (lstlen);
}

void	ft_print_list(t_stack *pile)
{
	t_stack	*temp;

	temp = pile;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
	temp = temp->next;
	}
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

//Creation des nodes
t_stack	*ft_lstnew_int(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
