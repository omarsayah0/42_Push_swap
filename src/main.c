/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:21:06 by oaletham          #+#    #+#             */
/*   Updated: 2025/11/03 17:30:09 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_stack_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_init(stack_a);
	stack_init(stack_b);
}

static void	both_stack_clear(t_stack *stack_a, t_stack *stack_b)
{
	stack_clear(stack_a);
	stack_clear(stack_b);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	both_stack_init(&a, &b);
	if (!parse_input(argc, argv, &a))
		both_stack_clear(&a, &b);
	if (is_sorted(&a))
	{
		stack_clear(&a);
		return (0);
	}
	if (a.size == 2)
		sort_2(&a);
	else if (a.size == 3)
		sort_3(&a);
	else if (a.size <= 5)
		sort_4_5(&a, &b);
	else
	{
		assignt_index(&a);
		radix_sort(&a, &b);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
