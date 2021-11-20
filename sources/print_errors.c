/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:00:03 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/20 15:29:23 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	print_error(int error)
{
	char	*message[1];

	message[ERROR] = "Error\n";
	ft_putstr_fd(message[error], 1);
	return (0);
}
