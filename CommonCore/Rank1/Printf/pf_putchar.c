/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:35:11 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 12:54:25 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putchar(int c)
{
	return (write(1, &c, 1));
}
/*
int	main(void)
{
	#include <stdio.h>

	int	count_ft;
	int	count_original;

	count_ft = 0;
	count_original = 0;

	printf("\n******* COMPARISON TESTS *******\n");
	printf("\n------- TEST0: a -------\n");
	count_ft = pf_putchar('a');
	printf(" >>> chars printed: %d\n", count_ft);
	count_original = printf("%c", 'a');
	printf(" >>> chars printed: %d\n", count_original);

        printf("\n------- TEST1: A -------\n");
        count_ft = pf_putchar('A');
        printf(" >>> chars printed: %d\n", count_ft);
        count_original = printf("%c", 'A');
        printf(" >>> chars printed: %d\n", count_original);

	printf("\n------- TEST2: 0 -------\n");
        count_ft = pf_putchar('0');
        printf(" >>> chars printed: %d\n", count_ft);
        count_original = printf("%c", '0');
        printf(" >>> chars printed: %d\n", count_original);

        printf("\n------- TEST3: 7 -------\n");
        count_ft = pf_putchar('7');
        printf(" >>> chars printed: %d\n", count_ft);
        count_original = printf("%c", '7');
        printf(" >>> chars printed: %d\n", count_original);
	return (0);
}*/
