/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:19:32 by catarina          #+#    #+#             */
/*   Updated: 2025/01/10 14:17:04 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	while (*top != NULL && (*top)->next != NULL)
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
	ft_printf("sa\n");
}
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("sa\n");
}