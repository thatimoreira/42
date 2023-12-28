/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 06:10:20 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 07:45:29 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_puthexadec(unsigned int num, const char format)
{
	int	i;
	int	remainder;
	int     args_amount;
	char	num_rev[20];

	i = 0;
	remainder = 0;
	args_amount = 0;
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
			{
				if (format == 'x')
					num_rev[i++] = remainder - 10 + 'a';
				if (format == 'X')
					num_rev[i++] = remainder - 10 + 'A';
			}
			num /= 16;
		}
		i--;
		while (i >= 0)
			args_amount += write(1, &num_rev[i--], 1);
	}
	return (args_amount);
}

int main(void)
{
	unsigned int nb;

	nb = 332;
	pf_puthexadec(nb, 'x');
	return (0);
}
