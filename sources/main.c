/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:25:12 by elima-me          #+#    #+#             */
/*   Updated: 2021/10/14 20:57:111 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*new_node(int num)
{
	t_stack	*node;
 
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL; 
	node->prev = NULL;
	return (node);
}

int	check_arg(char *arg, t_swap *swap)
{
	char	*split;
	int 	i;
	int 	j;
 
	j = 0;
	split = strtok(arg, " ");
	while (split[j])
	{
		i = 0;
		while(split[j][i])
		{
			if (!ft_isdigit(split[j][i]))
				exit(0);
			i++;
			swap->size_a++;
		}
		j++;
	}
	return (swap->size_a);
}
 
void	write_stack(t_swap *swap, char **arg, int argc)
{
	t_stack	*tmp;
	int		i;
 
	i = 0;
 
	while (argc != 0)
	{
		check_arg(arg[i], swap);
		tmp = new_node(arg[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_swap swap;
	(void)argc;
	swap.stack_a = NULL;
	swap.stack_b = NULL;
	swap.size_a = 0;
	swap.size_b = 0;
	if (argc < 2)
		exit(1);
	write_stack(&swap, argv + 1, argc);
	*argv+=1;
	while (*argv)
		printf("%s\n", *argv++);
}
