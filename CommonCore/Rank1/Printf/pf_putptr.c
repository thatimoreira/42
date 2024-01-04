/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:27 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 20:57:00 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_printptr(unsigned long long n)
{
	size_t	len;
	int	count;
	int	remainder;
	char	*num_conv;

	len = pf_numlen(n);
	count = len;
	remainder = 0;
	num_conv = (char *)malloc((len + 1) * sizeof(char));
	if (num_conv == NULL)
		return (0);
	num_conv[--len] = '\0';
	while (n)
	{
		remainder = n % 16;
		if (remainder < 10)
			num_conv[len--] = remainder + '0';
		else
			num_conv[len--] = remainder - 10 + 'a';
		n /= 16;
	}
	write(1, num_conv, count);
	free(num_conv);
	return (count);
}

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
		bytes_printed += pf_printptr(p);
	}
	return (bytes_printed);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <limits.h>

	char	*str;
	int	total_bytes;

	str = "Hello World!";
	total_bytes = pf_putptr(&str);
	printf("\n%d\n", total_bytes);
	printf("\nTripouille Failed at:\n");
	pf_putptr((void *)-1);
	printf("\nTest 1: %p\n\n", (void *)-1);
	pf_putptr((void *)16);
        printf("\nTest 4: %p\n\n", (void *)16);
	pf_putptr((void *)17);
        printf("\nTest 5: %p\n\n", (void *)17);
	pf_putptr((void *)LONG_MIN);
	printf("\n");
	pf_putptr((void *)LONG_MAX);
        printf("\nTest 6: %p e %p\n\n", (void *)LONG_MIN, (void *)LONG_MAX);
	pf_putptr((void *)INT_MIN);
	printf("\n");
	pf_putptr((void *)INT_MAX);
        printf("\nTest 7: %p e %p\n\n", (void *)INT_MIN, (void *)INT_MAX);
	pf_putptr((void *)ULONG_MAX);
	printf("\n");
	pf_putptr((void *)-ULONG_MAX);
        printf("\nTest 8: %p e %p\n\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("\nTripouille Succeded at test:\n");
	pf_putptr((void *)1);
        printf("\nTest 2: %p\n\n", (void *)1);
	pf_putptr((void *)15);
        printf("\nTest 3: %p\n\n", (void *)15);
	pf_putptr((void *)0);
        printf("\nTest 9: %p\n\n", (void *)0);
	return (0);
}*/
