/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:30:07 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/01/10 14:55:28 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_check(char *stack)
{
	int i = 0;
	int j;
	
	while (stack[i])
	{
		if (stack[i] <= '0' && stack[i] >= '9')
		{
			return (write (1, "Error\n", 6));
			//	return ;
		}
		if (*stack < INT_MIN || *stack > INT_MAX)
		{
			write (1, "Error\n", 6);
			//	return ;
		}
	}
	while (stack[i])
	{
			j = i + 1;
		while (stack[j])
		{
			if (stack[j] == stack[i])
			{
				write (1, "Error\n", 6);
				//	return ;
			}
			j++;
		}
		i++;
	}
}
