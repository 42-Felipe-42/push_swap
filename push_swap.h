/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:03:13 by plangloi          #+#    #+#             */
/*   Updated: 2024/02/02 13:27:53 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".libft/ft_printf/ft_printf.h"
# include ".libft/getnextline/get_next_line.h"
# include ".libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	bool			above_median;
	int				cost;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

// parsing des arguements
int					ft_check_input(char **arg);
int					ft_check_is_number(char *arg);
int					check_int(char *av);
int					ft_check_sign(char *arg);

// initialisation des piles apres verif des arguments
t_stack				*split_arg(char **av, t_stack **pile);
t_stack				*init_stack(char **av, int ac, t_stack **lsta);
void				init_stack_ba(t_stack *pile_a, t_stack *pile_b);
void				init_stack_ab(t_stack *pile_a, t_stack *pile_b);

// algo turk
t_stack				*for_three(t_stack **pile_a);
void				target_node_ab(t_stack *pile_a, t_stack *pile_b);
void				target_node_ba(t_stack *pile_b, t_stack *pile_a);
void				sort_arg(t_stack **pile_a, t_stack **pile_b);
void				cost_ab(t_stack *pile_a, t_stack *pile_b);
void				move_a_to_b(t_stack **pile_a, t_stack **pile_b);
void				move_b_to_a(t_stack **pile_a, t_stack **pile_b);
void				rr_cheapest_top(t_stack **pile_a, t_stack **pile_b,
						t_stack *cheapest_node);
void				rrr_cheapest_top(t_stack **pile_a, t_stack **pile_b,
						t_stack *cheapest_node);

// utils
t_stack				*ft_lstnew_int(int content);
t_stack				*find_min(t_stack *pile_a);
t_stack				*find_max(t_stack *pile_a);
t_stack				*get_cheapest(t_stack *pile);
int					is_sorted(t_stack *pile_a);
int					ft_listsize(t_stack *lst);
void				define_cheapest(t_stack *pile_a);
void				ft_free_stack(t_stack **a);
void				min_on_top(t_stack **pile_a);
void				find_index(t_stack *pile_a);
void				ft_print_list(t_stack *pile);
void				move_before_push(t_stack **pile, t_stack *top_node,
						int pile_name);

// instructions
void				make_push(t_stack **head_a, t_stack **head_b);
void				pa(t_stack **head_a, t_stack **head_b, int print);
void				pb(t_stack **head_b, t_stack **head_a, int print);
void				make_reverse_rotate(t_stack **pile);
void				rra(t_stack **pile_a, int print);
void				rrb(t_stack **pile_b, int print);
void				rrr(t_stack **pile_a, t_stack **pile_b, int print);
void				make_rotate(t_stack **pile);
void				ra(t_stack **pile_a, int print);
void				rb(t_stack **pile_b, int print);
void				rr(t_stack **pile_a, t_stack **pile_b, int print);
void				make_swap(t_stack **head);
void				sa(t_stack **pile_a, int print);
void				sb(t_stack **pile_b, int print);
void				ss(t_stack **pile_a, t_stack **pile_b, int print);
#endif