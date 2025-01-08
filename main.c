/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:00:56 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 15:06:23 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(stack_list *stack, char *name)
{
	ft_printf("Stack %s:\n", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
int	main(int ac, char **av)
{
	stack_list	*a;
	stack_list	*b;
	int	top_value;
	
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_stack_init(&a, av + (ac != 2));
	top_value = a->value;
	ft_printf("Initial ");
	print_stack(a, "A");
	ft_printf("Initial ");
	print_stack(b, "B");
	ra(&a);
	ft_printf("rotated ");
	print_stack(a, "A");
	rra(&a);
	ft_printf("reverse rotated ");
	print_stack(a, "A");
	sa(&a);
	ft_printf("swaped ");
	print_stack(a, "A");
	while(a)
	{
		pb(&b, &a);
	}
	ft_printf("pushed from a to b ");
	print_stack(b, "B");
	rb(&b);
	ft_printf("rotated ");
	print_stack(b, "B");
	rrb(&b);
	ft_printf("reverse rotated ");
	print_stack(b, "B");
	sb(&b);
	ft_printf("swaped ");
	print_stack(b, "B");
	while(b)
	{
		pa(&a, &b);
	}
	ft_printf("pushed from b to a ");
	print_stack(a, "A");
	pb(&b, &a);
	pb(&b, &a);
	ft_printf("new ");
	print_stack(a, "A");
	ft_printf("new ");
	print_stack(b, "B");
	rr (&a, &b);
	ft_printf("double rev ");
	print_stack(a, "A");
	print_stack(b, "B");
	rrr (&a, &b);
	ft_printf("double rr ");
	print_stack(a, "A");
	print_stack(b, "B");
	ss (&a, &b);
	ft_printf("double swap ");
	print_stack(a, "A");
	print_stack(b, "B");
	return (0);
}