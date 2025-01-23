/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:19:32 by catarina          #+#    #+#             */
/*   Updated: 2025/01/23 15:18:05 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	if (*top != NULL && (*top)->next != NULL)
	{
		first = *top;
		second = (*top)->next;
		first->next = second->next;
		second->next = first;
		*top = second;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}