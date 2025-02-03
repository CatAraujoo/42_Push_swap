/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:22:14 by catarina          #+#    #+#             */
/*   Updated: 2025/01/27 10:30:28 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
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

void	ft_set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	int		min_price;

	min_price = INT_MAX;
	if (!stack)
		return ;
	cheapest_node = NULL;
	while (stack != NULL)
	{
		stack->cheapest = false;
		if (stack->push_price < min_price)
		{
			min_price = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

t_stack	*ft_find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
