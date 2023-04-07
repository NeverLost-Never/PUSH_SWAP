/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:32:05 by mhaileye          #+#    #+#             */
/*   Updated: 2023/04/08 02:40:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	<stdio.h>
# include	<limits.h>
# include	"LIBFT/libft.h"
# include	"FT_PRINTF/ft_printf.h"

typedef struct t_Stack
{
	int				num;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct t_Stack	*next;
}	t_Stack;

int			validate_input(char *s[], int size);
t_Stack		*extract_stack(char *s[], int start, int end);
t_Stack		*init_node(int num);

int			push_to_b(t_Stack **a, t_Stack **b, int print);
int			push_to_a(t_Stack **b, t_Stack **a, int print);
int			rotate_a(t_Stack **a, int print);
int			rotate_b(t_Stack **b, int print);
int			r_rotate_a(t_Stack **a, int print);
int			r_rotate_b(t_Stack **b, int print);
int			swap_a(t_Stack **a, int print);
int			swap_b(t_Stack **b, int print);
int			r_rotate_all(t_Stack **a, t_Stack **b);
int			rotate_all(t_Stack **a, t_Stack **b);
int			swap_all(t_Stack **a, t_Stack **b);

int			sort_three(t_Stack **stack);
int			sort_two(t_Stack **stack, int order);
int			get_mid_point(t_Stack *stack);

void		assign_index(t_Stack *stack_a, int size);
void		push_until_three(t_Stack **stack_a, t_Stack **stack_b);
void		begin_sort(t_Stack **a, t_Stack **b);

int			is_sorted(t_Stack *stack, int order);
int			has_duplicate(t_Stack *stack);

void		print_stack(t_Stack *stack);
void		sort_stack(t_Stack **a, t_Stack **b);
int			free_stack(t_Stack **stack);

t_Stack		*get_tail(t_Stack *stack);
t_Stack		*get_before_tail(t_Stack *stack);
int			get_size(t_Stack *stack);

void		reset_position(t_Stack **stack);
void		assign_target_position(t_Stack **a, t_Stack **b);
int			locate_target(t_Stack **a, int b_index, int t_pos, int t_index);
void		calculate_all_cost(t_Stack **a, t_Stack **b);
void		calculate_lowest_cost(t_Stack **a, t_Stack **b);
void		move_lowest_cost(t_Stack **a, t_Stack **b, int cost_a, int cost_b);
void		check_cost_to_rotate(t_Stack **stack, char stck, int cost);
int			abs(int num);

void		shift_stack(t_Stack **stack);
int			get_lowest_index_pos(t_Stack **stack);

#endif