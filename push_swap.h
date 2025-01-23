/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:17 by catarina          #+#    #+#             */
/*   Updated: 2025/01/23 15:38:48 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int		value;
	int		index;
	int		push_price;
	bool	above_median;
	bool	cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

//handle errors
int		check_doubles (t_stack *stack_a, int nbr);
int		check_digit (char *stack_a);
void	ft_free_error(t_stack *stack_a);
void	ft_free_split(char **array);
void	free_stack(t_stack **stack);

//stack initiation;
void	append_node(t_stack **stack_a, int nbr);
void	stack_init(t_stack **stack_a, char **input);

//nodes initiation
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	init_a(t_stack *stack_a, t_stack *stack_b);
void	init_b(t_stack *stack_a, t_stack *stack_b);

//sorting prep and costs
void	ft_sorting(t_stack **stack_a, t_stack **stack_b);
void	current_index(t_stack *stack);
void	ft_set_cheapest(t_stack *stack);
t_stack	*ft_find_cheapest(t_stack *stack);
void min_on_top(t_stack **stack_a);

//stack utils
int		stack_len(t_stack *stack);
bool		A_is_sorted(t_stack *stack);
int		ft_find_median(t_stack *stack_a);
t_stack	*ft_find_last(t_stack *stack_a);
t_stack	*ft_find_highest(t_stack *stack_a);
t_stack	*ft_find_lowest(t_stack *stack_a);

//comands
void	swap(t_stack **top);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//algorithms
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack **stack_a);
void	big_sort(t_stack **stack_a, t_stack **stack_b);
//void	sort_five(t_stack **stack_a, t_stack **stack_b);

void	print_stack (t_stack **stack, char stack_name);
void debug_print_stacks(t_stack *stack_a, t_stack *stack_b, const char *message);
#endif 
