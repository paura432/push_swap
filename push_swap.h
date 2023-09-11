/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:58:13 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:20:06 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct t_list_stack
{
	int					content;
	int					index;
	struct t_list_stack	*next;
}stack;

int		main(int argc, char **argv);
void	ft_inistack(int argc, char **argv, stack **stack_a);
int		check_doubles(stack *stack_a);
int		check_errors(char **argv, stack *stack_a);
stack	*lstlast(stack *lst);
void	lstadd_back(stack **lst, stack *new);
void	lstadd_front(stack **lst, stack *new);
int		lstsize(stack *lst);
stack	*lstnew(int content, int index);

void	sa(stack *stack_a);
void	sb(stack *stack_b);
void	ss(stack *stack_a, stack *stack_b);
void	pa(stack **stack_a, stack **stack_b);
void	pb(stack **stack_a, stack **stack_b);

void	ra(stack **stack_a);
void	rb(stack **stack_b);
void	rr(stack **stack_a, stack **stack_b);
void	rra(stack **stack_a, int i);
void	rrb(stack **stack_b, int i);
void	rrr(stack **stack_a, stack **stack_b, int i);

void	init_algorithm(stack **stack_a, stack **stack_b);
void	index_satck(stack **stack_a);
int		stack_biggestindex(stack *stack_a);
int		stack_biggestnum(stack *stack_a);
int		stack_lower(stack *stack_a);
void	litle_sort(stack **stack_a);
int		check_divisions(stack *stack_a, int i);
void	first_sort(stack **stack_b, stack **stack_a, int i, int division);
void	print_stack(stack *stack_a);
void	sort_a2b(stack **stack_a, stack **stack_b, int division, int i);
void	sort_b2a(stack **stack_a, stack **stack_b, int division, int i);
int		second_sort(stack **stack_b, stack **stack_a);
int		third_sort(stack **stack_b, stack **stack_a, int division);
void	sort_chunk(stack **stack_a, stack **stack_b, int division);
int		serch_num_b2a(stack **stack_a, stack **stack_b, int division);
int		serch_num_a2b(stack **stack_a, stack **stack_b, int division);

#endif
