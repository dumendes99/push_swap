/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:45:26 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/13 20:00:26 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	normalize(t_info *info)
{
	t_stack	*helper;
	t_stack	*aux;
	int		new_value;

	helper = info->temp;
	while (helper != NULL)
	{
		new_value = 1;
		aux = info->temp;
		while (aux != NULL)
		{
			if (helper->num > aux->num)
				new_value++;
			aux = aux->next;
		}
		ps_lstadd_back(&info->stack_a, new_node(new_value));
		helper = helper->next;
	}
}
