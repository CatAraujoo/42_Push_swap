/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:31:23 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 14:53:07 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(stack_list **stack)
{
	stack_list	*last;
	stack_list	*temp;
	
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = NULL;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp;
	last->next = NULL;
	temp = *stack;
	temp->next = *stack;
	*stack = temp;
}
void	rra(stack_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}
void	rrb(stack_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
void	rrr(stack_list **stack_a, stack_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}