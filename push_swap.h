/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:17 by catarina          #+#    #+#             */
/*   Updated: 2025/01/03 15:17:20 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_list
{
	int		value;
	int		index;
	int		push_price;
	bool	above_median;
	bool	cheapest;
	struct s_stack_list		*target_node;
	struct s_stack_list		*next;
	struct s_stack_list		*prev;
}	stack_list;

void	sort_two(stack_list **stack_a);
//void	sort_three(stack_list **stack_a);
int		A_is_sorted(stack_list *stack);
int		stack_len(stack_list *stack);
void	swap(stack_list **top);
void	sa(stack_list **stack_a);
void	sb(stack_list **stack_b);
void	ss(stack_list **stack_a, stack_list **stack_b);
void	pa(stack_list **stack_a, stack_list **stack_b);
void	pb(stack_list **stack_a, stack_list **stack_b);
void	rotate(stack_list **stack);
void	ra(stack_list **stack_a);
void	rb(stack_list **stack_b);
void	rr(stack_list **stack_a, stack_list **stack_b);
void	reverse_rotate(stack_list **stack);
void	rra(stack_list **stack_a);
void	rrb(stack_list **stack_b);
void	rrr(stack_list **stack_a, stack_list **stack_b);

#endif
