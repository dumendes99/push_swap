/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:17:34 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 18:16:55 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	two_elements(t_info *info)
{
	if (info->stack_a->num > info->stack_a->next->num)
		swap(&info->stack_a, sa);
}

void	three_elements(t_stack **stack)
{
	int	algo;

	algo = find_algo(stack);
	if (algo == 1)
		swap(stack, sa);
	if (algo == 2)
	{
		swap(stack, sa);
		reverse_rotate(stack, rra);
	}
	if (algo == 3)
		rotate(stack, ra);
	if (algo == 4)
	{
		swap(stack, sa);
		rotate(stack, ra);
	}
	if (algo == 5)
		reverse_rotate(stack, rra);
}

void	four_elements(t_info *info)
{
	send_smallest(info);
	three_elements(&info->stack_a);
	push_a(info);
}

void	five_elements(t_info *info)
{
	send_smallest(info);
	send_smallest(info);
	three_elements(&info->stack_a);
	push_a(info);
	push_a(info);
}

void	short_sort(t_info *info)
{
	if (info->size_a == 2)
		two_elements(info);
	else if (info->size_a == 3)
		three_elements(&info->stack_a);
	else if (info->size_a == 4)
		four_elements(info);
	else if (info->size_a == 5)
		five_elements(info);
}
