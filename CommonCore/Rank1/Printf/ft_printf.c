/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:07:14 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 03:29:45 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	def_function(va_list ap, const char arg_type)
{
	int	args_amount;

	args_amount = 0;
	if (arg_type == 'c')
		args_amount += ft_putchar(va_arg(ap, int));
	return (args_amount);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		total_args;

	i = 0;
	total_args = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			total_args += def_function(ap, format[i + 1]);
			i += 2;
		}
		else
		{
			total_args += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (total_args);
}

int	main(void)
{
	#include <stdio.h>

	int	elements_ft;
	int	elements_original;
	char	*test;

	test = "Hello, World";
	printf("------- FT_PRINTF test -------\n");
	/*elements_ft = ft_printf("%s", elements_ft);
	ft_printf("\nTeste0: %c\nTeste1: %s\nTeste2: %p\n
                Teste3: %d\nTeste4: %i\nTeste5: %u\n
                Teste6: %x\nTeste7: %X\nTeste8:%%\n\n",
		'a', s, &s,
		7, 21, 3,
		7, 21);*/
	elements_ft = ft_printf("%c", 'z');
	printf("\nElements total: %d\n", elements_ft); //changes to ft_printf function when %d is defined

	printf("------- PRINTF test -------\n");
	/*elements_original = printf("%s", elements_original);
	printf("\nTeste0: %c\nTeste1: %s\nTeste2: %p\n
                Teste3: %d\nTeste4: %i\nTeste5: %u\n
                Teste6: %x\nTeste7: %X\nTeste8:%%",
                'a', s, &s,
                7, 21, 3,
                7, 21);*/
	elements_original = printf("%c", 'z');
	printf("\nElements total: %d\n", elements_original);
	return (0);
}
