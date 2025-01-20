/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:23:55 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/01/20 11:24:35 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_len(*stack_a) == 2)
		sort_two(*stack_a);
	else if (stack_len(*stack_a) == 3)
		sort_three(stack_a);
	else
		big_sort(stack_a, stack_b);
}
void	sort_two(t_stack *stack_a)
{
	int	temp;
	
	if (stack_a->value > stack_a->next->value)
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
		write (1, "sa\n", 3);
	}
}
void	sort_three(t_stack **stack_a)
{
	int a, b, c;

    a = (*stack_a)->value;
    b = (*stack_a)->next->value;
    c = (*stack_a)->next->next->value;

    if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    /*else if (a > b && b > c && a > c)
        ra(stack_a);*/
    else if (a > b && b < c && a < c)
        sa(stack_a);
	else if (a > b && b < c && a > c)
	{
		ra(stack_a);
	}
	else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}
/*void	sort_five(t_stack **stack_a)
{
	t_stack	*biggest_node;
	
	biggest_node = ft_find_highest(*stack_a);
	while (stack_a)
	{
		if (biggest_node == *stack_a)
			ra(stack_a);
		else if ((*stack_a)->next == biggest_node)
			rra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		
	} 
}*/
