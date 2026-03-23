/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:43:59 by oaletham          #+#    #+#             */
/*   Updated: 2025/11/03 17:30:25 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	t_node	*node;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		error_exit();
	node = stack->top;
	while (i < stack->size)
	{
		arr[i] = node->val;
		i++;
		node = node->next;
	}
	return (arr);
}

static void	insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < n)
	{
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		i++;
	}
}

void	assignt_index(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = stack_to_array(stack);
	insertion_sort(arr, stack->size);
	node = stack->top;
	while (node)
	{
		i = 0;
		while (i < stack->size)
		{
			if (node->val == arr[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(arr);
}

static int	get_max_bits(t_stack *stack)
{
	t_node	*node;
	int		max_num;
	int		max_bit;

	node = stack->top;
	max_num = 0;
	max_bit = 0;
	while (node)
	{
		if (node->index > max_num)
			max_num = node->index;
		node = node->next;
	}
	while (max_num >> max_bit != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	move;
	int	size;
	int	index;
	int	max_bit;

	max_bit = get_max_bits(stack_a);
	move = 0;
	while (move < max_bit)
	{
		size = stack_a->size;
		while (size--)
		{
			index = stack_a->top->index;
			if (((index >> move) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size)
			pa(stack_a, stack_b);
		move++;
	}
}
