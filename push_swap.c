/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:43:03 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 15:13:54 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	A_is_sorted(stack_list *stack);
int	stack_len(stack_list *stack);

/*int	main(int ac, char **av)
{
	stack_list	*stack;

	stack = av[1];
	
	if (!stack)
		return (NULL);
	if (A_is_sorted(stack) == 0)
		exit ;
	if (stack_len(stack) <= 5)
		sort_small_stack(stack);
}*/

int	A_is_sorted(stack_list *stack)
{
	while (stack)
	{
		if (stack > stack->next)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	stack_len(stack_list *stack)
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