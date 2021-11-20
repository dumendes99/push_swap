/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:09:38 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/20 15:29:00 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	checker_digit(char **args, int count_args, int count)
{
	while (args[count_args])
	{
		while (args[count_args][count])
		{
			if ((!ft_isdigit(args[count_args][count])
				&& args[count_args][count] != '-')
				|| (count > 0 && args[count_args][count] == '-'))
				return (0);
			count++;
		}
		count_args++;
	}
	return (1);
}

int	check_isdigit(char *argv[])
{
	int		count_argv;
	int		i[2];
	char	**args;

	count_argv = 1;
	while (argv[count_argv])
	{
		i[0] = 0;
		i[1] = 0;
		args = ft_split(argv[count_argv], ' ');
		if (!checker_digit(args, i[0], i[1]))
		{
			freeall(args);
			return (0);
		}
		freeall(args);
		count_argv++;
	}
	return (1);
}

int	minimal_args(int argc)
{
	if (argc < 3)
		return (0);
	return (1);
}

int	fill_stack(char **argv, t_stack **stack, t_info *info)
{
	char	**args;
	int		count_argv;
	int		count_args;

	count_argv = 1;
	while (argv[count_argv])
	{
		count_args = 0;
		args = ft_split(argv[count_argv], ' ');
		while (args[count_args])
		{
			ps_lstadd_back(stack, new_node(ft_atoi(args[count_args])));
			info->size_a++;
			if (!check_double(stack, ft_atoi(args[count_args])))
			{
				freeall(args);
				freelist(*stack);
				return (0);
			}
			count_args++;
		}
		freeall(args);
		count_argv++;
	}
	return (1);
}

int	handler_inputs(int argc, char *argv[], t_info *info)
{
	if (!minimal_args(argc))
		return (0);
	if (!check_isdigit(argv))
		return (print_error(ERROR));
	if (!fill_stack(argv, &info->temp, info))
		return (print_error(ERROR));
	return (1);
}
