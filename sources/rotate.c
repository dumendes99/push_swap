/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:29:13 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:01 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack **stack, int print)
{
	t_stack	*temp;

	temp = *stack;
	ps_lstadd_back(stack, new_node(temp->num));
	del_first_node(stack);
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
