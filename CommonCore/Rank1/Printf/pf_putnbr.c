/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:55:12 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 13:47:05 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	treat_negative(int n)
{
	int	c_printed;

	c_printed = 0;
	if (n == -2147483648)
		c_printed += write(1, "-2147483648", 11);
	else if (n < 0)
		c_printed += write(1, "-", 1);
	return (c_printed);
}

int	pf_putnbr(int num)
{
	char	num_rev[12];
	int		i;
	int	chars_printed;

	i = 0;
	chars_printed = 0;
	if (num == 0)
		return (write(1, "0", 1));
	else if (num < 0)
	{
		chars_printed += treat_negative(num);
		if (num < 0 && num != -2147483648)
			num *= -1;
	}
	while (num > 0)
	{
		num_rev[i++] = (num % 10) + 48;
		num /= 10;
	}
	i--;
	while (i >= 0)
		chars_printed += write(1, &num_rev[i--], 1);
	return (chars_printed);
}
/*
int	main (void)
{
	#include <stdio.h>

	int	d;
	int	i;
	int	count_d;
	int	count_i;

	d = -42;
	i = -2147483648;
	count_d = pf_putnbr(d);
	printf("\ncount_d:%d\n\n", count_d);
	count_i = pf_putnbr(i);
	printf("\ncount_i: %i\n", count_i);
	return (0);
}*/
