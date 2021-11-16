/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:36:54 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 20:54:02 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	del_last(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last_node;

	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	if (temp->next)
		temp->next = NULL;
	free(last_node);
}

void	reverse_rotate(t_stack **stack, int print)
{
	t_stack *last;
	t_stack	*first;
	t_stack	*pen;

	last = ps_lstlast(*stack);
	first = *stack;
	pen = *stack;
	while (pen->next->next != NULL)
		pen = pen->next;
	pen->next = NULL;
	last->next = first;
	*stack = last;
	if (print == rra)
		ft_putstr_fd("rra\n", 1);
	if (print == rrb)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_r(t_info *info)
{
	reverse_rotate(&info->stack_a, 9);
	reverse_rotate(&info->stack_b, 9);
	ft_putstr_fd("rrr\n", 1);
}
