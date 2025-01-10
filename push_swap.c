/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:43:03 by catarina          #+#    #+#             */
/*   Updated: 2025/01/10 14:16:24 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	A_is_sorted(t_stack *stack);
int	stack_len(t_stack *stack);

/*int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = av[1];
	
	if (!stack)
		return (NULL);
	if (A_is_sorted(stack) == 0)
		exit ;
	if (stack_len(stack) <= 5)
		sort_small_stack(stack);
}*/

int	A_is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack > stack->next)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	stack_len(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}