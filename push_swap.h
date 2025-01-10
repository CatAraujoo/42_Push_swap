/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:17 by catarina          #+#    #+#             */
/*   Updated: 2025/01/10 14:15:37 by cmatos-a         ###   ########.fr       */
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

typedef struct s_t_stack
{
	int		value;
	int		index;
	int		push_price;
	bool	above_median;
	bool	cheapest;
	struct s_t_stack		*target_node;
	struct s_t_stack		*next;
	struct s_t_stack		*prev;
}	t_stack;

void	sort_two(t_stack **stack_a);
//void	sort_three(t_stack **stack_a);
int		A_is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	swap(t_stack **top);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif 
