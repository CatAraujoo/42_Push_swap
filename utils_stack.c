/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:16 by catarina          #+#    #+#             */
/*   Updated: 2025/01/17 11:09:36 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack_a)
{
	int	i;

	if (!stack_a)
		return (0);
	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);	
}
int	A_is_sorted (t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

t_stack	*ft_find_last(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		stack_a = stack_a->next;
	}
	return (stack_a);
}
t_stack	*ft_find_highest(t_stack *stack_a)
{
	t_stack	*highest_node;

	if (!stack_a)
		return (NULL);
	highest_node = stack_a;
	while (stack_a)
	{
		if (stack_a->value > highest_node->value)
			highest_node = stack_a;
		stack_a = stack_a->next;
	}
	return (highest_node);
}
t_stack	*ft_find_lowest(t_stack *stack_a)
{
	t_stack	*lowest_node;

	if (!stack_a)
		return (NULL);
	lowest_node = stack_a;
	while (stack_a)
	{
		if (stack_a->value < lowest_node->value)
			lowest_node = stack_a;
		stack_a = stack_a->next;
	}
	return (lowest_node);
}
int	ft_find_median(t_stack *stack_a)
{
	int	len;
	int	res;
	
	len = stack_len(stack_a);
	res = len / 2;
	if (res % 1 == 0)
		return (res);
	else
		return (res + 1);
}