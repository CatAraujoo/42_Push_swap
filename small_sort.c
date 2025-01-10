/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:23:55 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/01/10 14:15:54 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
void	sort_three(t_stack **stack_a)
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
		
}
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