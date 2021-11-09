/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:14:05 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/07 18:33:07 by elima-me         ###   ########.fr       */
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
	t_stack	*aux;

	aux = info->stack_a;
	ps_lstadd_front(&info->stack_b, new_node(aux->num));
	del_first_node(&info->stack_a);
	info->size_a--;
	info->size_b++;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_info *info)
{
	t_stack	*aux;

	aux = info->stack_b;
	ps_lstadd_front(&info->stack_a, new_node(aux->num));
	del_first_node(&info->stack_b);
	info->size_a++;
	info->size_b--;
	ft_putstr_fd("pa\n", 1);
}
