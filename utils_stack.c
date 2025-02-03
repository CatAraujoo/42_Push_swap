/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:16 by catarina          #+#    #+#             */
/*   Updated: 2025/01/27 14:15:35 by cmatos-a         ###   ########.fr       */
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
	t_stack		*highest_node;
	int			max;

	if (!stack_a)
		return (NULL);
	max = INT_MIN;
	while (stack_a)
	{
		if (stack_a->value > max)
		{
			max = stack_a->value;
			highest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (highest_node);
}

t_stack	*ft_find_lowest(t_stack *stack_a)
{
	t_stack	*lowest_node;
	long	min;

	if (!stack_a)
		return (NULL);
	min = LONG_MAX;
	while (stack_a)
	{
		if (stack_a->value < min)
		{
			min = stack_a->value;
			lowest_node = stack_a;
		}
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
	if (res % 2 == 0)
		return (res);
	else
		return (res + 1);
}
