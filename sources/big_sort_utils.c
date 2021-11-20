/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:15:20 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/18 21:16:58 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_biggest(t_stack **stack, int *biggest)
{
	t_stack	*temp;
	int		position;
	int		moves;

	temp = *stack;
	position = 0;
	moves = 0;
	while (temp != NULL)
	{
		if (*biggest < temp->num)
		{
			*biggest = temp->num;
			position = moves;
		}
		temp = temp->next;
		moves++;
	}
	return (position);
}

void	send_rest_to_b(t_info *info)
{
	int	number;
	int	position;
	int	decision;

	while (info->rest)
	{
		number = 0;
		position = find_biggest(&info->stack_a, &number);
		decision = rotate_or_reverse(info->size_a, position);
		to_b(info, number, decision);
		info->rest--;
	}
	organize_b(info);
}

void	to_b(t_info *info, int num, int decision)
{
	while (info->stack_a->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_a, rra);
		if (decision == 2)
			rotate(&info->stack_a, ra);
	}
	push_b(info);
}
