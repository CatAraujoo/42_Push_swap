/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:44:05 by catarina          #+#    #+#             */
/*   Updated: 2025/01/17 15:54:42 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);	
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		av = args;
		stack_init_a(&stack_a, args);
		ft_free_split(args);
	}
	else
		stack_init_a(&stack_a, av + 1);
	if (A_is_sorted(stack_a) == 0)
		ft_sorting(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
}
