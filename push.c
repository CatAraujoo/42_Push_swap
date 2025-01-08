/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:03:36 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 12:15:08 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(stack_list **stack_a, stack_list **stack_b)
{
	stack_list	*temp;
	
	if (*stack_b != NULL)
	{
		temp = *stack_a;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	ft_printf("pa\n");
}
void	pb(stack_list **stack_a, stack_list **stack_b)
{
	stack_list	*temp;
	
	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	ft_printf("pb\n");
}