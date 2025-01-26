/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:22:14 by catarina          #+#    #+#             */
/*   Updated: 2025/01/24 15:39:02 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_price = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_price = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_price += stack_a->target_node->index;
		else 
			stack_a->push_price += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}
static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;
	
	while (stack_b)
	{
		best_match_index = LONG_MAX; 
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = ft_find_lowest(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_target_b(stack_a, stack_b);
}
