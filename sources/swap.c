/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:11:26 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/18 20:37:36 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack **stack, int print)
{
	t_stack	*swap;
	t_stack	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	swap = *stack;
	*stack = (*stack)->next;
	(*stack)->next = swap;
	swap->next = third;
	if (print == sa)
		ft_putstr_fd("sa\n", 1);
	if (print == sb)
		ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_info *stacks)
{
	swap(&stacks->stack_a, 9);
	swap(&stacks->stack_b, 9);
	ft_putstr_fd("ss\n", 1);
}
