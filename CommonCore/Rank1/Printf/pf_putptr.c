/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:27 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 19:18:35 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putptr(void *ptr)
{
	int			bytes_printed;
	unsigned long long	p;

	bytes_printed = 0;
	p = (unsigned long long)ptr;
	if (p == 0)
		bytes_printed += write(1, "(nil)", 5);
	else
	{
		bytes_printed = write(1, "0x", 2);
		bytes_printed += pf_puthexadec((unsigned long long)p, 'x');
	}
	return (bytes_printed);
}
