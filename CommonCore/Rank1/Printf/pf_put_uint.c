/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:30:01 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 12:41:49 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_put_uint(unsigned int num)
{
	int	i;
	int	chars_printed;
	char	num_rev[12];

        i = 0;
        chars_printed = 0;
        if (num == 0)
                return (write(1, "0", 1));
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
int	main(void)
{
	#include <stdio.h>
	#include <limits.h>

	unsigned int	n;
	unsigned int	int_min;
	unsigned int	int_max;
	unsigned int	uint_max;
	int		count_ft;
	int		count_original;

	n = 0;
	int_min = INT_MIN;
	int_max = INT_MAX;
	uint_max = UINT_MAX;
	count_ft = 0;
	count_original;

	printf("\n***** COMPARISON TESTS *****\n");
	printf("\n-------------- TEST0: 0 --------------\n");
	count_ft = pf_put_uint(n);
	printf(" >>> chars printed: %u\n", count_ft);
	count_original = printf("%u", n);
	count_original = printf(" >>> chars printed: %u\n", count_original);

	printf("\n----------- TEST1: int_min -----------\n");
        count_ft = pf_put_uint(int_min);
        printf(" >>> chars printed: %u\n", count_ft);
        count_original = printf("%u", int_min);
        count_original = printf(" >>> chars printed: %u\n", count_original);

	printf("\n----------- TEST2: int_max -----------\n");
        count_ft = pf_put_uint(int_max);
        printf(" >>> chars printed: %u\n", count_ft);
        count_original = printf("%u", int_max);
        count_original = printf(" >>> chars printed: %u\n", count_original);

	printf("\n---------- TEST4: uint_max ----------\n");
        count_ft = pf_put_uint(uint_max);
        printf(" >>> chars printed: %u\n", count_ft);
        count_original = printf("%u", uint_max);
        count_original = printf(" >>> chars printed: %u\n", count_original);
	return (0);
}*/
