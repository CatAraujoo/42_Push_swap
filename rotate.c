/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:02 by catarina          #+#    #+#             */
/*   Updated: 2025/01/10 14:16:54 by cmatos-a         ###   ########.fr       */
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
	ft_printf("ra\n");
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}