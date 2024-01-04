/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:27 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 19:13:05 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putptr(void *ptr)
{
	int			args_amount;
	unsigned long long	p;

	p = (unsigned long long ptr;)
	args_amount = write(1, "0x", 2);
	if (ptr == 0)
		args_amount += write(1, "0", 1);
	else
		args_amount += pf_puthexadec((unsigned long long)ptr, 'x');
	return (args_amount);
}
