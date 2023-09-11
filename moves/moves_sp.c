/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:00:53 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:14:38 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(stack *stack_a)
{
	int	aux;
	int	index;

	if (stack_a == NULL)
		return ;
	if (stack_a->next != NULL && stack_a != NULL)
	{
		aux = stack_a->content;
		index = stack_a->index;
		stack_a->content = stack_a->next->content;
		stack_a->index = stack_a->next->index;
		stack_a->next->content = aux;
		stack_a->next->index = index;
	}
	write(1, "sa\n", 3);
}

void	sb(stack *stack_b)
{
	int	aux;
	int	index;

	if (stack_b == NULL)
		return ;
	if (stack_b->next != NULL && stack_b != NULL )
	{
		aux = stack_b->content;
		index = stack_b->index;
		stack_b->content = stack_b->next->content;
		stack_b->index = stack_b->next->index;
		stack_b->next->content = aux;
		stack_b->next->index = index;
	}
	write(1, "sb\n", 3);
}

void	ss(stack *stack_a, stack *stack_b)
{
	int	aux;

	if (stack_b == NULL && stack_a == NULL)
		return ;
	if (stack_a->next != NULL && stack_a != NULL)
	{
		aux = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = aux;
	}
	if (stack_b->next != NULL && stack_b != NULL )
	{
		aux = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = aux;
	}
	write(1, "ss\n", 3);
}

void	pa(stack **stack_a, stack **stack_b)
{
	stack	*aux;

	aux = (*stack_b)->next;
	if (stack_b != NULL)
		lstadd_front(stack_a, *stack_b);
	if (stack_b == NULL)
	{
		stack_b = NULL;
		return ;
	}
	*stack_b = aux;
	write(1, "pa\n", 3);
}

void	pb(stack **stack_a, stack **stack_b)
{
	stack	*aux;

	if (stack_a == NULL)
		return ;
	aux = (*stack_a)->next;
	if (stack_a != NULL)
		lstadd_front(stack_b, *stack_a);
	*stack_a = aux;
	write(1, "pb\n", 3);
}
