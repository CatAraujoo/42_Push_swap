/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:02 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 14:30:38 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(stack_list **stack)
{
	stack_list	*temp;
	stack_list	*first;
	
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
void	ra(stack_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void	rb(stack_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
void	rr(stack_list **stack_a, stack_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}