/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:45:39 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:16:55 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_inistack(int argc, char **argv, stack **stack_a)
{
	stack	*aux;
	char	**spl_arr;
	int		i;
	int		j;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			j = 0;
			spl_arr = ft_split(argv[i], ' ');
			while (spl_arr[j])
			{
				aux = lstnew(ft_atoi(spl_arr[j]), 0);
				lstadd_back(stack_a, aux);
				j++;
			}
			i++;
		}
	}
}

void	print_stack(stack *stack_a)
{
	printf("\n");
	printf("stack_a\n");
	while (stack_a)
	{
		printf("num:%d\n", stack_a->content);
		printf("index:%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
}

int	main(int argc, char **argv)
{
	stack	*stack_a;
	stack	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (write(1, "Error\n", 6));
	ft_inistack(argc, argv, &stack_a);
	if (!check_errors(argv, stack_a))
		return (write(1, "Error\n", 6));
	init_algorithm(&stack_a, &stack_b);
	return (0);
}
