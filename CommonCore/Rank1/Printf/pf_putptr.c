/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:27 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 06:05:41 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putptr(unsigned long long ptr)
{
	int	args_amount;

	args_amount = write(1, "0x", 2);
	if (ptr == 0)
		args_amount += write(1, "0", 1);
	else
	{
		pf_printptr(ptr);
		args_amount += pf_puthexadec(ptr);
	}
	return (args_amount);
}
