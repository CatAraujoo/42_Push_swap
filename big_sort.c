/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:29:52 by catarina          #+#    #+#             */
/*   Updated: 2025/01/24 10:35:35 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
        rr(stack_a, stack_b);
    while (*stack_a != cheapest_node)
        ra(stack_a);
    while (*stack_b != cheapest_node->target_node)
        rb(stack_b);
    current_index(*stack_a);
    current_index(*stack_b);
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
        rrr(stack_a, stack_b);
    while (*stack_a != cheapest_node)
        rra(stack_a);
    while (*stack_b != cheapest_node->target_node)
        rrb(stack_b);
    current_index(*stack_a);
    current_index(*stack_b);
}
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	
	ft_set_cheapest(*stack_a); 
	cheapest = ft_find_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a);
}

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b); 
}
void	print_stack (t_stack **stack, char stack_name)
{
	while (*stack != NULL)
	{
		printf("stack: %c: %d\n", stack_name, (*stack)->value);
		*stack = (*stack)->next;
	}
}
void	min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->value != ft_find_lowest(*stack_a)->value)
	{
		if ((*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
void debug_print_stacks(t_stack *stack_a, t_stack *stack_b, const char *message)
{
    printf("\n%s\n", message);
    printf("Stack A: ");
    while (stack_a) {
        printf("%d ", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("\nStack B: ");
    while (stack_b) {
        printf("%d ", stack_b->value);
        stack_b = stack_b->next;
    }
    printf("\n");
}
void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !A_is_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !A_is_sorted(*stack_a))
		pb(stack_b, stack_a);
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