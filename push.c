/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:03:36 by catarina          #+#    #+#             */
/*   Updated: 2025/01/17 13:12:34 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	
	if (*stack_b != NULL)
	{
		temp = *stack_a;
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
		//temp->next = *stack_b;
		*stack_b = temp;
	}
	write (1, "pb\n", 3);
}