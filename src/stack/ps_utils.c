/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:23:55 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/29 17:22:50 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*n;

	n = stack->top;
	while (n && n->next)
	{
		if (n->val > n->next->val)
			return (0);
		n = n->next;
	}
	return (1);
}

void	swap(t_stack *stack)
{
	int	a;
	int	b;

	if (stack->size < 2)
		return ;
	a = stack->top->val;
	b = stack->top->next->val;
	stack->top->val = b;
	stack->top->next->val = a;
	a = stack->top->index;
	b = stack->top->next->index;
	stack->top->index = b;
	stack->top->next->index = a;
}

void	rotate_up(t_stack *stack)
{
	t_node	*first;
	t_node	*w;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	w = stack->top;
	while (w->next)
		w = w->next;
	w->next = first;
}

void	rotate_down(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	if (stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
