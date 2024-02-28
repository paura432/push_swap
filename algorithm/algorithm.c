/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:53 by pramos            #+#    #+#             */
/*   Updated: 2024/02/28 12:11:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	litle_sort(t_stack **stack_a)
{
	int	biggest;

	biggest = stack_biggestindex(*stack_a);
	if ((*stack_a)->index == biggest)
		ra(stack_a);
	else if ((*stack_a)->next->index == biggest)
		rra(stack_a, 0);
	if ((*stack_a)->index == biggest - 1)
		sa(*stack_a);
}

int	check_list(t_stack **stack_a)
{
	int			index;
	t_stack		*stack_aux;

	index = 0;
	stack_aux = *stack_a;
	while (stack_aux->next != NULL)
	{
		if (stack_aux->index != index)
			return (1);
		index++;
		stack_aux = stack_aux->next;
	}
	return (0);
}

int	check_divisions(t_stack *stack_a, int i)
{
	int	divisions;

	divisions = stack_biggestindex(stack_a) + 1;
	divisions /= i;
	return (divisions);
}

void	init_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	divisions;
	int	i;

	i = 10;
	index_satck(stack_a);
	if (stack_biggestindex(*stack_a) + 1 > 200)
		i = 14;
	if (!check_list(stack_a))
		exit(0);
	divisions = check_divisions(*stack_a, i);
	sort_a2b(stack_a, stack_b, divisions, i);
	divisions = stack_biggestindex(*stack_a) + 1;
	litle_sort(stack_a);
	sort_b2a(stack_a, stack_b, divisions, i);
}

int	serch_num_b2a(t_stack **stack_a, t_stack **stack_b, int division)
{
	t_stack	*stack_aux;
	int		i;

	i = 0;
	if (stack_b == NULL)
		return (i);
	stack_aux = (*stack_b);
	while (stack_aux->index >= division)
	{
		if (stack_aux->index + 1 == (*stack_a)->index
			|| (*stack_b)->index == lstlast(*stack_a)->index + 1)
		{
			i = 1;
			break ;
		}
		stack_aux = stack_aux->next;
	}
	return (i);
}
