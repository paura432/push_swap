/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:53 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:42:54 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	litle_sort(stack **stack_a)
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

int	check_divisions(stack *stack_a, int i)
{
	int	divisions;

	divisions = stack_biggestindex(stack_a) + 1;
	divisions /= i;
	return (divisions);
}

void	init_algorithm(stack **stack_a, stack **stack_b)
{
	int	divisions;
	int	i;

	i = 10;
	index_satck(stack_a);
	if (stack_biggestindex(*stack_a) + 1 > 100)
		i = 18;
	divisions = check_divisions(*stack_a, i);
	sort_a2b(stack_a, stack_b, divisions, i);
	divisions = stack_biggestindex(*stack_a) + 1;
	litle_sort(stack_a);
	sort_b2a(stack_a, stack_b, divisions, i);
}
