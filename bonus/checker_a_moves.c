/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_a_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaileye <mhaileye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:40:24 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/10 20:14:05 by mhaileye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

int	swap_a(struct t_Stack **a, int print)
{
	t_Stack	*first;
	t_Stack	*second;
	int		tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	first = *a;
	second = (*a)->next;
	tmp = first->num;
	first->num = second->num;
	second->num = tmp;
	tmp = first->index;
	first->index = second->index;
	second->index = tmp;
	if (print)
		ft_printf("sa\n");
	return (1);
}

int	push_to_a(struct t_Stack **b, struct t_Stack **a, int print)
{
	t_Stack	*head;

	if (*b == NULL)
		return (0);
	head = *b;
	*b = (*b)->next;
	head->next = *a;
	*a = head;
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	rotate_a(struct t_Stack **a, int print)
{
	t_Stack	*first;
	t_Stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	first = *a;
	last = *a;
	*a = (*a)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_printf("ra\n");
	return (1);
}

int	r_rotate_a(struct t_Stack **a, int print)
{
	t_Stack	*last;
	t_Stack	*first;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	last = *a;
	while (last->next->next)
		last = last->next;
	first = last->next;
	first->next = *a;
	*a = first;
	last->next = NULL;
	if (print)
		ft_printf("rra\n");
	return (1);
}
