/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:52:02 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/29 16:29:20 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->size == 2 && stack_a->top->val > stack_a->top->next->val)
		sa(stack_a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->val;
	y = a->top->next->val;
	z = a->top->next->next->val;
	if (x < y && y < z)
		return ;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	find_min_num_pos(t_stack *stack_a)
{
	int		min;
	int		index;
	int		pos;
	t_node	*tmp;

	index = 0;
	pos = 0;
	min = stack_a->top->val;
	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->val < min)
		{
			min = tmp->val;
			pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (pos);
}

static void	bring_min_num_pos_top(t_stack *stack_a, int pos)
{
	int	i;

	if (pos <= stack_a->size / 2)
	{
		while (pos--)
			ra(stack_a);
	}
	else
	{
		i = stack_a->size - pos;
		while (i--)
			rra(stack_a);
	}
}

void	sort_4_5(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_a->size > 3)
	{
		pos = find_min_num_pos(stack_a);
		bring_min_num_pos_top(stack_a, pos);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (stack_b->size)
		pa(stack_a, stack_b);
}
