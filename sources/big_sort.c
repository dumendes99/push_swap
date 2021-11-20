/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:13:10 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/18 21:16:40 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	to_a(t_info *info, int num, int decision)
{
	while (info->stack_b->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_b, rrb);
		if (decision == 2)
			rotate(&info->stack_b, rb);
	}
	push_a(info);
}

void	organize_b(t_info *info)
{
	int		biggest;
	int		position;
	int		decision;

	while (info->size_b)
	{
		biggest = 0;
		position = find_biggest(&info->stack_b, &biggest);
		decision = rotate_or_reverse(info->size_b, position);
		to_a(info, biggest, decision);
	}
}

int	first_match(t_info *info, int small_ref, int bigger_ref, int *number)
{
	t_stack	*temp;
	int		position;

	temp = info->stack_a;
	position = 0;
	while (temp != NULL)
	{
		if (temp->num >= small_ref && temp->num <= bigger_ref)
		{
			*number = temp->num;
			return (position);
		}
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	organize_a(t_info *info)
{
	int	i;
	int	number;
	int	decision;
	int	position;

	i = info->groups - 1;
	while (info->groups)
	{
		position = first_match(info, (info->group_size * i), (info->group_size
					* info->groups) - 1, &number);
		decision = rotate_or_reverse(info->size_a, position);
		to_b(info, number, decision);
		if (info->size_b == info->group_size)
		{
			i--;
			info->groups--;
			organize_b(info);
		}
	}
}

void	big_sort(t_info *info)
{
	if (info->size_a <= 100)
		info->group_size = 20;
	else if (info->size_a > 100
		&& info->size_a <= 250)
		info->group_size = 25;
	else if (info->size_a > 250
		&& info->size_a <= 500)
		info->group_size = 50;
	info->groups = (info->size_a / info->group_size);
	info->rest = info->size_a - (info->groups * info->group_size);
	if (info->rest)
		send_rest_to_b(info);
	organize_a(info);
}
