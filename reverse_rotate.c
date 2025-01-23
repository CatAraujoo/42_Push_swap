/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:31:23 by catarina          #+#    #+#             */
/*   Updated: 2025/01/23 15:48:58 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	 t_stack *last;
    t_stack *second_last;

    if (!*stack || !(*stack)->next)
        return;
    
    last = ft_find_last(*stack);
    second_last = last->prev;

    // Remove last from the end
    second_last->next = NULL;

    // Make last the new head
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write (1, "rrr\n", 4);
}