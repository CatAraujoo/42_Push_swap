/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:44:05 by catarina          #+#    #+#             */
/*   Updated: 2025/02/03 11:41:33 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (1);
		av = args;
		stack_init(&stack_a, av, ac, args);
		ft_free_split(args);
	}
	else
		stack_init(&stack_a, av + 1, ac, NULL);
	if (a_is_sorted(stack_a) == false)
		ft_sorting(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
