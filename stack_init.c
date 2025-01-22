/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:28:28 by catarina          #+#    #+#             */
/*   Updated: 2025/01/22 11:05:39 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long	ft_atol(const char *str)//tested
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
void	append_node(t_stack **stack_a, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = nbr;
	new_node->cheapest = 0;
	if (!(*stack_a))
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
void	stack_init(t_stack **stack_a, char **input)
{
	int		i;
	long	nbr;

	i = 0;
	while (input[i])
	{
		if (check_digit(input[i]) != 1)
			ft_free_error(*stack_a);
		nbr = ft_atol(input[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_free_error(*stack_a);
		if (check_doubles(*stack_a, (int)nbr) == 1)
			ft_free_error(*stack_a);
		append_node(stack_a, (int)nbr);
		i++;
	}
}
void	prep_for_push(t_stack **stack, t_stack *target, char stack_name)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
		{
			if (target->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (target->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
//6 13 4 14 19 3 18 8 11 15 17 2 1 7 12 9 10 16 5 wrong!!!
/*int	main(int ac, char **av)
{
	t_stack *new_stack;
	t_stack *temp = av[1];
	
	stack_init_a(new_stack, temp);
	printf("%d", stack_len(temp));
}*/