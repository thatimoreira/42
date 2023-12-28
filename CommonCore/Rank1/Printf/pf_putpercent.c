/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:48:09 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 17:55:07 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putpercent(void)
{
	return (write(1, "%", 1));
}
/*
int	main(void)
{
	#include <stdio.h>

	int	count;

	count = 0;
	count = pf_putpercent();
	printf("\ncount = %d\n", count);
	return (0);
}*/
