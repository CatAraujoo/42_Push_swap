/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:31:23 by catarina          #+#    #+#             */
/*   Updated: 2025/01/22 10:04:28 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	
	if (!*stack || !(*stack)->next)
		return ;
	last = ft_find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (!print)
		write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (!print)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		write (1, "rrr\n", 4);
}