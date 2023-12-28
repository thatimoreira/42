/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:30:01 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 17:23:38 by tsoares-         ###   ########.fr       */
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

	unsigned int	n;
	int		count;

	n = 111;
	count = 0;
	count = pf_put_uint(n);
	printf("\ncount = %u\n", count);
	return (0);
}*/
