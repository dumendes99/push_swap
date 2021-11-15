/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:13:10 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 18:21:50 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


// I'WILL USE THIS OF DIFERENT FORM IN SOME POINT
// 
// int find_smallest(int *position, int *smallest, t_info *info)
// {
// 	t_stack *temp;
// 	temp = info->stack_a;
// 	while (temp->next != NULL)
// 	{
// 		if (*smallest > temp->num)
// 			*smallest = temp->num;
// 		temp = temp->next;
// 		*position = *position + 1;
// 	}
// 	return (0);
// }

int	find_biggest(t_stack **stack, int *biggest)
{
	t_stack *temp;
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

void to_a(t_info *info, int num, int decision)
{
	t_stack *temp;

	temp = info->stack_b;
	while (info->stack_b->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_b, rrb);
		if (decision == 2)
			rotate(&info->stack_b, rb);
		temp = temp->next;
	}
	temp = NULL;
	push_a(info);
}

void organize_b(t_info *info)
{
	int		biggest;
	int		position;
	int		decision;

	while (info->size_b - 1)
	{
		biggest = 0;
		position = find_biggest(&info->stack_b, &biggest);
		decision = rotate_or_reverse(info->size_b, position);
		to_a(info, biggest, decision);
	}
}

int	first_match(t_info *info, int small_ref, int bigger_ref, int *number)
{
	t_stack *temp;
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

void to_b(t_info *info, int num, int decision)
{
	t_stack *temp;

	temp = info->stack_a;
	while (info->stack_a->num != num)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_a, rra);
		if (decision == 2)
			rotate(&info->stack_a, ra);
	}
	push_b(info);
}

void	big_sort(t_info *info)
{
	int	i;
	int number;
	int position;
	int decision;

	number = MAX_INT;
	decision = 0;
	info->group_size = 20;
	info->groups = (info->size_a / info->group_size);
	info->rest = info->size_a - (info->groups * info->group_size);
	i = info->groups - 1;
	while (info->stack_a)
	{
		if (info->size_b == info->group_size)
		{
			i--;
			info->groups--;
			break ;			
		}
		position = first_match(info, info->group_size * i, (info->group_size * info->groups), &number);
		decision = rotate_or_reverse(info->size_a, position);
		to_b(info, number, decision);
	}
	organize_b(info);
}

// int		sort_till_100(t_info *info)
// { 
// 	int	range;
// 	int	position;
// 	int decision;
// 	int num;

// 	num = MAX_INT;
// 	range = info->size_a / 4;
// 	range = range * 3;
// 	while (info->size_b < 20)
// 	{
// 		position = first_match(info, range, &num);
// 		decision = rotate_or_reverse(info->size_a, position);
// 		to_b(info, num, decision);
// 	}
// 	organize_b(info);
// 	return (0);
// }

