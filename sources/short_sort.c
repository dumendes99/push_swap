/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:17:34 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/13 20:47:19 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	two_elements(t_stack *stack)
{
	if (stack->num > stack->next->num)
		swap(&stack, sa);
}

void	short_sort(t_info *info)
{
	if (info->size_a == 2)
		two_elements(info->stack_a);
	if (info->size_a <= 3)
		three_elements(&info->stack_a);
	if (info->size_a <= 5)
		five_elements(info);


}

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
	while (info->stack_a->num != smallest)
	{
		if (decision == 1)
			reverse_rotate(&info->stack_a, rra);
		if (decision == 2)
			rotate(&info->stack_a, ra);
	}
	push_b(info);
}

void	five_elements(t_info *info)
{
	send_smallest(info);
	send_smallest(info);
	three_elements(&info->stack_a);
	push_a(info);
	push_a(info);
}
