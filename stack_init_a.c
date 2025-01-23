/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:46:32 by catarina          #+#    #+#             */
/*   Updated: 2025/01/23 16:01:24 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}
static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = ft_find_highest(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

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

void	ft_set_cheapest(t_stack *stack)
{
	t_stack *cheapest;
    int min_price = INT_MAX;

    if (!stack)
        return;

    cheapest = NULL;
    while (stack != NULL)
    {
        stack->cheapest = false;  // Reset cheapest flag
        if (stack->push_price < min_price)
        {
            min_price = stack->push_price;
            cheapest = stack;
        }
        stack = stack->next;
    }

    if (cheapest)
        cheapest->cheapest = true;
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

void	init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	ft_set_cheapest(stack_a);
}