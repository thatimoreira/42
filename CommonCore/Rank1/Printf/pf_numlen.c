/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:33 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 12:14:15 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	pf_numlen(unsigned long long num)
{
	size_t	num_len;

	num_len = 0;
	if (num == 0)
		num_len++;
	while (num)
	{
		num /= 16;
		num_len++;
	}
	return (num_len);
}
