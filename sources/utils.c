/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:32:59 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/20 15:31:45 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*new_node(long int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

int	check_double(t_stack **stack, long int num)
{
	t_stack	*temp;
	int		times;

	temp = *stack;
	times = 0;
	if (num > MAX_INT || num < MIN_INT)
		return (0);
	while (temp)
	{
		if (temp->num == num)
			times++;
		if (times == 2)
			return (0);
		temp = temp->next;
	}
	temp = NULL;
	return (1);
}

void	freelist(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	freeall(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
