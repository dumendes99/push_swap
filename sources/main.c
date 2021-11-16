/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:15:19 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/15 22:32:31 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
}

void	init_struct(t_info *info)
{
	ft_bzero(info, sizeof(t_info));
}

int	main(int argc, char *argv[])
{
	t_info	info;

	init_struct(&info);
	if (!handler_inputs(argc, argv, &info))
		return (1);
	normalize(&info);
	freelist(info.temp);
	if (info.size_a <= 5)
		short_sort(&info);
	else
		big_sort(&info);
	freelist(info.stack_a);
	return (0);
}
