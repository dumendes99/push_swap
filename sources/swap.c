/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:11:26 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/07 18:34:41 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack **stack, int print)
{
	t_stack *first; 
	t_stack *second;
	
	first = *stack;
	second = (*stack)->next;
	if (!(*stack)->next)
		return ;
	first->next = first->next->next;
	*stack = second;
	second->next = first;
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
