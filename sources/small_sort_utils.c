/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:25:01 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/18 21:13:34 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rotate_or_reverse(int size, int position)
{
	int	half;

	half = size / 2;
	if (half <= position)
		return (1);
	else if (half > position)
		return (2);
	return (0);
}

int	find_algo(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->num > temp->next->num
		&& temp->num < temp->next->next->num)
		return (1);
	else if (temp->next->num < temp->num
		&& temp->next->num > temp->next->next->num)
		return (2);
	else if (temp->next->next->num > temp->next->num
		&& temp->next->next->num < temp->num)
		return (3);
	else if (temp->next->next->num < temp->next->num
		&& temp->next->next->num > temp->num)
		return (4);
	else if (temp->num < temp->next->num
		&& temp->num > temp->next->next->num)
		return (5);
	return (0);
}

void	send_smallest(t_info *info)
{
	t_stack	*aux;
	int		smallest;
	int		count;
	int		position;
	int		decision;

	count = 1;
	position = 0;
	smallest = MAX_INT;
	aux = info->stack_a;
	while (aux != NULL)
	{
		if (smallest > aux->num)
		{
			smallest = aux->num;
			position = count;
		}
		aux = aux->next;
		count++;
	}
	decision = rotate_or_reverse(info->size_b, position);
	to_b(info, smallest, decision);
}
