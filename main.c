/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:30:04 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 22:26:47 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = extract_stack(argv, 0, argc);
	stack_b = NULL;
	if (!stack_a && ft_printf("%E", "Error\n"))
		return (0);
	if (has_duplicate(stack_a) && ft_printf("%E", "Error\n"))
		return (0);
	if (is_sorted(stack_a, 1))
		return (0);
	assign_index(stack_a, get_size(stack_a) + 1);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	free_stack(t_Stack **stack)
{
	t_Stack	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return (1);
}
