/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:27 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 11:34:44 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putptr(void *ptr)
{
	int		args_amount;
	unsigned long long	p;

	p = (unsigned long long)ptr;
	args_amount = write(1, "0x", 2);
	if (ptr == 0)
		args_amount += write(1, "0", 1);
	else
		args_amount += pf_puthexadec(p, 'x');
	return (args_amount);
}
/*
int	main (void)
{
	#include <stdio.h>

	int	num;
	void	*pt;
	int	count;
	int	count2;

	num = 0;
	pt = &num;
	count = pf_putptr(pt);
	ft_printf("\ncount: %d\n", count);
	return (0);
}*/
