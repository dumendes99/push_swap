/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chancheg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:51:20 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 18:26:01 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_element;

	last_element = ps_lstlast(*lst);
	if (last_element != NULL)
	{
		last_element->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		new->next = NULL;
	}
}

void	ps_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	new->next = *stack;
	*stack = new;
}
