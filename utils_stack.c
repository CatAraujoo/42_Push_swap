/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:00:16 by catarina          #+#    #+#             */
/*   Updated: 2025/01/24 13:44:54 by catarina         ###   ########.fr       */
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
bool	A_is_sorted (t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
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
	if (res % 2 == 0)
		return (res);
	else
		return (res + 1);
}
/*int ft_find_median(t_stack *stack_a)
{
    int len;
    int *arr;
    int median;
    int i;
    t_stack *temp;

    len = stack_len(stack_a);
    arr = malloc(sizeof(int) * len);
    if (!arr)
        return 0;  // Error handling
    i = 0;
    temp = stack_a;
    while (temp)
    {
        arr[i++] = temp->value;
        temp = temp->next;
    }
    for (i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }

    median = arr[len / 2];
    free(arr);
    return median;
}*/
