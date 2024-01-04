/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:33 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 19:52:02 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	pf_numlen(unsigned long long num)
{
	size_t	num_len;

	num_len = 0;
	while (num)
	{
		num /= 16;
		num_len++;
	}
	return (num_len);
}
