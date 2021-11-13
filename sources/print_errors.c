/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:00:03 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/12 18:26:10 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	print_error(int error)
{
	char	*message[SIZE_ERROR];

	message[ERR_FEW_PARAMETERS] = "ERROR, At least three arguments\n";
	message[ERR_INVALID_INPUT] = "ERROR, Invalid inputs, please follow\n"
		"the of the arguments\n";
	message[ERR_NOT_IS_DIGIT] = "ERROR, Only digits must be gived\n";
	message[ERROR] = "ERROR\n";
	ft_putstr_fd(message[error], 1);
	return (0);
}
