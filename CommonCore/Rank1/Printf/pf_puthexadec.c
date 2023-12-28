/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:10:20 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 08:09:17 by tsoares-         ###   ########.fr       */
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

int	pf_puthexadec(unsigned int num, const char format)
{
	int	i;
	int	remainder;
	int     args_amount;
	char	num_rev[20];

	i = 0;
	remainder = 0;
	if (num == 0)
		args_amount = write(1, "0", 1);
	else
	{
		while (num)
		{
			remainder = num % 16;
			if (remainder <= 9)
				num_rev[i++] = remainder + '0';
			else
				num_rev[i++] = def_format(remainder, format);
			num /= 16;
		}
		i--;
		while (i >= 0)
			args_amount += write(1, &num_rev[i--], 1);
	}
	return (args_amount);
}