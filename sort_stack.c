/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:15:12 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 15:16:23 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(stack_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
/*void	sort_three(stack_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->value;
	if (a > b && b > c && A_is_sorted(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	
	
}*/
	/*t_list	*list_start;
	
	if (!stack)
		return ;
	list_start = stack;
	while (stack->next)
	{
		if (!(*cmp)(stack->value, stack->next->value))
		{
			swap_values(&stack->value, &stack->next->value);
			stack = list_start;
		}
		else
			stack = stack->next;
	}
	return (*list_start);
}
void	swap_values(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
int ascending(int a, int b)
{
	return (a <= b);
}*/