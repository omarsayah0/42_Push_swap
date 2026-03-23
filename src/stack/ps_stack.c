/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:34:36 by oaletham          #+#    #+#             */
/*   Updated: 2025/11/03 15:34:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

int	stack_is_empty(t_stack *stack)
{
	if (stack->size == 0)
		return (1);
	return (0);
}

void	stack_push(t_stack *stack, int new_number, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc (sizeof(*new_node));
	if (!new_node)
	{
		stack_clear(stack);
		error_exit();
	}
	new_node->val = new_number;
	new_node->index = index;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	stack_pop(t_stack *stack, int *out, int *index)
{
	t_node	*tmp;

	if (stack_is_empty(stack))
		return (0);
	tmp = stack->top;
	if (out)
		*out = tmp->val;
	if (index)
		*index = tmp->index;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (1);
}

void	stack_clear(t_stack *stack)
{
	while (stack->size > 0)
		stack_pop(stack, NULL, NULL);
}
