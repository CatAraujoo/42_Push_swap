/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:30:07 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/01/17 16:01:15 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles (t_stack *stack_a, int nbr)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
int	check_digit (char *stack_a)
{
	int	i;

	i = 0;
	if (stack_a[i] != '-' && stack_a[i] != '+' && (stack_a[i] <= '0' && stack_a[i] >= '9'))
			return (1);
	if (stack_a[i] == '-' || stack_a[i] == '+')
		i++;
	while (stack_a[i])
	{
		if (!(stack_a[i] >= '0' && stack_a[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node->next;
		node->value = 0;
		free(node);
		node = temp;
	}
	*stack = NULL;
}

void	ft_free_error(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	ft_free_stack(&stack_a);
	write (1, "Error\n", 6);
	exit(1);
}
void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}
/*int	main(int ac, char **av)
{
	long nbr = ft_atol(av[1]);
	
	printf("%ld", nbr);
	printf("%d", check_digit(av[1]));
	
	return (0);
}*/
