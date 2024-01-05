/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:10:20 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 14:01:01 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	def_format(int remainder, const char arg_type)
{
	if (arg_type == 'x')
		remainder = remainder - 10 + 'a';
	if (arg_type == 'X')
		remainder = remainder - 10 + 'A';
	return (remainder);
}

static int	pf_printhex(unsigned int num, const char format)
{
	size_t	len;
	int	count;
	int	remainder;
	char	*num_conv;

	remainder = 0;
	len = pf_numlen(num);
	count = len;
	num_conv = (char *)malloc((len + 1) * sizeof(char));
	if (num_conv == NULL)
		return (0);
	num_conv[--len] = '\0';
	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			num_conv[len--] = remainder + '0';
		else
			num_conv[len--] = def_format(remainder, format);
		num /= 16;
	}
	write(1, num_conv, count);
	free(num_conv);
	return (count);
}

int     pf_puthexadec(unsigned int num, const char format)
{
	int	bytes_printed;

	bytes_printed = 0;
	if (num == 0)
		bytes_printed = write(1, "0", 1);
	else
		bytes_printed = pf_printhex(num, format);
	return (bytes_printed);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <limits.h>

	unsigned int	n1;
	int		count_ft;

	n1 = 0;
	count_ft = 0;
	printf("\n******* COMPARISON TESTS *******\n");
	printf("\n------- TEST 0: %u -------\n", n1);
	count_ft = pf_puthexadec(n1, 'x');
	printf(" >>> chars printed: %d\n", count_ft);
	count_ft = printf("%x", n1);
        printf(" >>> chars printed: %d\n\n", count_ft);
	count_ft = pf_puthexadec(n1, 'X');
        printf(" >>> chars printed: %d\n", count_ft);
	count_ft = printf("%X", n1);
        printf(" >>> chars printed: %d\n\n", count_ft);

	printf("\n----- TEST 1: %u -----\n", INT_MIN);
        count_ft = pf_puthexadec(INT_MIN, 'x');
        printf(" >>> chars printed: %d\n", count_ft);
	count_ft = printf("%x", INT_MIN);
        printf(" >>> chars printed: %d\n\n", count_ft);
	count_ft = pf_puthexadec(INT_MIN, 'X');
        printf(" >>> chars printed: %d\n", count_ft);
        count_ft = printf("%X", INT_MIN);
        printf(" >>> chars printed: %d\n\n", count_ft);

	printf("\n----- TEST 2: %u -----\n", INT_MAX);
	count_ft = pf_puthexadec(INT_MAX, 'x');
        printf(" >>> chars printed: %d\n", count_ft);
	count_ft = printf("%x", INT_MAX);
        printf(" >>> chars printed: %d\n\n", count_ft);
        count_ft = pf_puthexadec(INT_MAX, 'X');
        printf(" >>> chars printed: %d\n", count_ft);
        count_ft = printf("%X", INT_MAX);
        printf(" >>> chars printed: %d\n\n", count_ft);

	printf("\n----- TEST 3: %u -----\n", UINT_MAX);
        count_ft = pf_puthexadec(UINT_MAX, 'x');
        printf(" >>> chars printed: %d\n", count_ft);
        count_ft = printf("%x", UINT_MAX);
        printf(" >>> chars printed: %d\n\n", count_ft);
        count_ft = pf_puthexadec(UINT_MAX, 'X');
        printf(" >>> chars printed: %d\n", count_ft);
        count_ft = printf("%X", UINT_MAX);
        printf(" >>> chars printed: %d\n\n", count_ft);
	return (0);
}*/
