/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:03:36 by catarina          #+#    #+#             */
/*   Updated: 2025/01/24 15:09:33 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}


void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b); 
	write (1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a) //dest, src
{
	push(stack_b, stack_a);
	write (1, "pb\n", 3);
}
/*void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	
	if (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	write (1, "pa\n", 3);
}
void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*temp;
	
	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write (1, "pb\n", 3);
}*/