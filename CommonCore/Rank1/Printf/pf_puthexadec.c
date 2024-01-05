/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:10:20 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 21:23:38 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	def_format(int remainder, const char arg_type)
{
	if (arg_type == 'x')
		remainder = remainder - 10 + 'a';
	if (arg_type == 'X')
		remainder = remainder - 10 + 'A';
	return (remainder);
}

int	pf_printhex(unsigned int num, const char format)
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
