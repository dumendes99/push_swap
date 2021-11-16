/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:29:13 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:52 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack **stack, int print)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = ps_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	if (print == ra)
		ft_putstr_fd("ra\n", 1);
	if (print == rb)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_info *info)
{
	rotate(&info->stack_a, 9);
	rotate(&info->stack_b, 9);
	ft_putstr_fd("rr\n", 1);
}
