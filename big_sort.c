/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:29:52 by catarina          #+#    #+#             */
/*   Updated: 2025/01/22 12:13:17 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	int max_iterations = stack_len(*stack_a) + stack_len(*stack_b);
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node && max_iterations--)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	int max_iterations = stack_len(*stack_a) + stack_len(*stack_b);
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node && max_iterations--)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = ft_set_cheapest(*stack_a); 
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	//prep_for_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a, false);
}

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, false); 
}
void	print_stack (t_stack *stack_a)
{
	t_stack *top = stack_a;
	
	while (top != NULL)
	{
		printf("%d\n", top->value);
		top = top->next;
	}
}
static void	min_on_top(t_stack **stack_a)
{
	while (*stack_a != ft_find_lowest(*stack_a))
	{
		if ((*stack_a)->value > ft_find_median(*stack_a))
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !A_is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !A_is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !A_is_sorted(*stack_a))
	{
		init_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
