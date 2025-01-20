/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:02 by catarina          #+#    #+#             */
/*   Updated: 2025/01/16 14:50:34 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	first = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	*stack = first->next;
	first->next = NULL;
	temp->next = first;
}
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}