/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:55:12 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 14:23:30 by tsoares-         ###   ########.fr       */
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

int	main (void)
{
	#include <stdio.h>
	#include <limits.h>

	int	count_d;
	int	count_i;
	int	count_original;

	count_d = 0;
	count_i = 0;
	count_original = 0;

	printf("\n******* COMPARISON TESTS *******\n");
	printf("\n----------- TEST 0: %d -----------\n", 0);
	count_d = pf_putnbr(0);
        printf(" >>> count_d: %d char(s) printed\n", count_d);
	count_original = pf_putnbr(0);
        printf(" >>> count_d: %d char(s) printed\n\n", count_original);
	count_i = pf_putnbr(0);
        printf(" >>> count_i: %i char(s) printed\n", count_i);
	count_original = pf_putnbr(0);
        printf(" >>> count_i: %i char(s) printed\n\n", count_original);

        printf("\n----------- TEST 1: %d -----------\n", INT_MIN);
        count_d = pf_putnbr(INT_MIN);
        printf(" >>> count_d: %d char(s) printed\n", count_d);
        count_original = pf_putnbr(INT_MIN);
        printf(" >>> count_d: %d char(s) printed\n\n", count_original);
        count_i = pf_putnbr(INT_MIN);
        printf(" >>> count_i: %i char(s) printed\n", count_i);
        count_original = pf_putnbr(INT_MIN);
        printf(" >>> count_i: %i char(s) printed\n\n", count_original);

	printf("\n----------- TEST 2: %d -----------\n", INT_MAX);
        count_d = pf_putnbr(INT_MAX);
        printf(" >>> count_d: %d char(s) printed\n", count_d);
        count_original = pf_putnbr(INT_MAX);
        printf(" >>> count_d: %d char(s) printed\n\n", count_original);
        count_i = pf_putnbr(INT_MAX);
        printf(" >>> count_i: %i char(s) printed\n", count_i);
        count_original = pf_putnbr(INT_MAX);
        printf(" >>> count_i: %i char(s) printed\n\n", count_original);

	printf("\n----------- TEST 3: %d -----------\n", UINT_MAX);
        count_d = pf_putnbr(UINT_MAX);
        printf(" >>> count_d: %d char(s) printed\n", count_d);
        count_original = pf_putnbr(UINT_MAX);
        printf(" >>> count_d: %d char(s) printed\n\n", count_original);
        count_i = pf_putnbr(UINT_MAX);
        printf(" >>> count_i: %i char(s) printed\n", count_i);
        count_original = pf_putnbr(UINT_MAX);
        printf(" >>> count_i: %i char(s) printed\n\n", count_original);
	return (0);
}
