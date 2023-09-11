/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:49:13 by pramos            #+#    #+#             */
/*   Updated: 2023/06/05 16:48:39 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(stack **stack_a)
{
	int		aux;
	int		index_aux;
	stack	*stack_aux;

	if (stack_a == NULL)
		return ;
	index_aux = (*stack_a)->index;
	aux = (*stack_a)->content;
	stack_aux = (*stack_a)->next;
	(*stack_a) = stack_aux;
	lstadd_back(stack_a, lstnew(aux, index_aux));
	write(1, "ra\n", 3);
}

void	rb(stack **stack_b)
{
	int		aux;
	int		index_aux;
	stack	*stack_aux;

	if (stack_b == NULL)
		return ;
	index_aux = (*stack_b)->index;
	aux = (*stack_b)->content;
	stack_aux = (*stack_b)->next;
	(*stack_b) = stack_aux;
	lstadd_back(stack_b, lstnew(aux, index_aux));
	write(1, "rb\n", 3);
}

void	rr(stack **stack_a, stack **stack_b)
{
	int		aux;
	stack	*stack_aux;

	if (stack_a == NULL || stack_a == NULL)
		return ;
	aux = (*stack_a)->content;
	stack_aux = (*stack_a)->next;
	(*stack_a) = stack_aux;
	lstadd_back(stack_a, lstnew(aux, (*stack_a)->index));
	aux = (*stack_b)->content;
	stack_aux = (*stack_b)->next;
	(*stack_b) = stack_aux;
	lstadd_back(stack_b, lstnew(aux, (*stack_a)->index));
	write(1, "rr\n", 3);
}
