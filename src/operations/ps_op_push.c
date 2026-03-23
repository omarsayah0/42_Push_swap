/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:13:50 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/29 20:41:43 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	index;

	if (stack_pop(stack_b, &num, &index))
	{
		stack_push(stack_a, num, index);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	index;

	if (stack_pop(stack_a, &num, &index))
	{
		stack_push(stack_b, num, index);
		write(1, "pb\n", 3);
	}
}
