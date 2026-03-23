/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:32:08 by oaletham          #+#    #+#             */
/*   Updated: 2025/11/03 17:31:26 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_token(char	*token, t_stack *stack_a)
{
	int		num;
	t_node	*contains;

	if (!ps_atoi(token, &num))
		return (0);
	contains = stack_a->top;
	while (contains)
	{
		if (contains->val == num)
			return (0);
		contains = contains->next;
	}
	stack_push(stack_a, num, 0);
	return (1);
}

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	set_j(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j])
		j++;
	j--;
	return (j);
}

static void	free_token_array_on_error(char **tokens, t_stack *a)
{
	if (tokens)
		free_tokens(tokens);
	stack_clear(a);
	error_exit();
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**tokens;

	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i >= 1)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
			free_token_array_on_error(tokens, a);
		j = set_j(tokens);
		while (j >= 0)
		{
			if (!process_token(tokens[j--], a))
				free_token_array_on_error(tokens, a);
		}
		free_tokens(tokens);
		i--;
	}
	return (1);
}
