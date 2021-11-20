/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:14:05 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/18 20:24:30 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	del_first_node(t_stack **stack)
{
	t_stack	*temp;

	if ((*stack)->next == NULL)
		free((*stack));
	else
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		free(temp);
		temp = NULL;
	}
}

void	push_b(t_info *info)
{
	t_stack	*first_a;
	t_stack	*first_b;

	first_a = info->stack_a;
	info->stack_a = info->stack_a->next;
	first_b = info->stack_b;
	info->stack_b = first_a;
	first_a->next = first_b;
	info->size_a--;
	info->size_b++;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_info *info)
{
	t_stack	*first_b;
	t_stack	*first_a;

	first_b = info->stack_b;
	info->stack_b = info->stack_b->next;
	first_a = info->stack_a;
	info->stack_a = first_b;
	first_b->next = first_a;
	info->size_a++;
	info->size_b--;
	ft_putstr_fd("pa\n", 1);
}
