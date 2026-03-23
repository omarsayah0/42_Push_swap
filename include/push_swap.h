/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:25:40 by oaletham          #+#    #+#             */
/*   Updated: 2025/11/03 17:30:54 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	error_exit(void);
void	stack_init(t_stack *stack);
int		stack_is_empty(t_stack *stack);
void	stack_push(t_stack *stack, int new_number, int index);
int		stack_pop(t_stack *stack, int *out, int *index);
void	stack_clear(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		ps_atoi(const char *str, int *out);
int		is_sorted(t_stack *stack);
void	swap(t_stack *stack);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_4_5(t_stack *stack_a, t_stack *stack_b);
int		parse_input(int argc, char **argv, t_stack *a);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	assignt_index(t_stack *stack);
#endif