/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:32:29 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 17:56:02 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	pf_numlen(unsigned long long nb, int bs)
{
	size_t	num_len;

	num_len = 0;
	if (nb == 0)
		num_len++;
	else if (nb < 0)
	{
		num_len++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= bs;
		num_len++;
	}
	return (num_len);
}

int	pf_unsitoa(unsigned int num, int base)
{
	size_t			len;
	int			bytes_printed;
	unsigned long long	n;
	char			*num_conv;
	int			remainder;

	n = (unsigned long long)num;
	bytes_printed = 0;
	len = pf_numlen(n, base);
	remainder = 0;
	num_conv = (char *)malloc((len + 1) * sizeof(char));
	if (num_conv == NULL)
		return (NULL);
	if (n == 0)
		num_conv[0] = '0';
	if (n < 0)
	{
		num_conv[0] = '-';
		n *= -1;
	}
	num_conv[len--] = '\0';
	while (n)
	{
		remainder = n % base;
		if (remainder < 10)
			num_conv[len--] = (n % base + '0');
		else
			num_conv[len--] = (n % base) - 10 + 'a';
		n /= base;
	}
	write (1, num_conv, bytes_printed);
	free (num_conv);
	return (bytes_printed);
}

int	main(void)
{
	#include <stdio.h>
	#include <limits.h>

	unsigned int	n;
	int		count;

	n = UINT_MAX;
	count = 0;
	count = pf_unsitoa(n, 10);
	printf("\ncount = %u\n", count);
	printf("\nprintf: %u\n", n);
	return (0);
}
