/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:26:37 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/17 10:12:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;
	char	*line;
	char	*moves;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	if (!is_stack_valid(&stack_a, argc, argv))
		return (0);
	stack_b = NULL;
	moves = get_next_line(STDIN_FILENO);
	while (moves != NULL)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		moves = ft_strjoin(moves, line, 1);
		free_up(&line);
	}
	if (is_sorted(stack_a, 1) && moves == NULL && free_stack(&stack_a))
		return (ft_printf("OK\n") * 0);
	parse_moves(moves, &stack_a, &stack_b);
	free_up(&moves);
	return (1);
}

int	is_stack_valid(t_Stack **stack, int argc, char **argv)
{
	*stack = extract_stack(argv, 0, argc);
	if (!(*stack) && ft_printf("%E", "Error\n"))
		return (0);
	if (has_duplicate(stack) && ft_printf("%E", "Error\n"))
		return (0);
	return (1);
}
