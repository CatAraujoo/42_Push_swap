/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:19:32 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 14:59:38 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack_list **top)
{
	stack_list	*first;
	stack_list	*second;

	while (*top != NULL && (*top)->next != NULL)
	{
		first = *top;
		second = (*top)->next;
		first->next = second->next;
		second->next = first;
		*top = second;
	}
}

void	sa(stack_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}
void	sb(stack_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}
void	ss(stack_list **stack_a, stack_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("sa\n");
}