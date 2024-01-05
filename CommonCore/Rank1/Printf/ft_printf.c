/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:07:14 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/05 09:23:56 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	def_function(va_list ap, const char arg_type)
{
	int	args_amount;

	args_amount = 0;
	if (arg_type == 'c')
		args_amount += pf_putchar(va_arg(ap, int));
	else if (arg_type == 's')
		args_amount += pf_putstr(va_arg(ap, char *));
	else if (arg_type == 'p')
		args_amount += pf_putptr(va_arg(ap, void *));
	else if (arg_type == 'd' || arg_type == 'i')
		args_amount += pf_putnbr(va_arg(ap, int));
	else if	(arg_type == 'u')
		args_amount += pf_put_uint(va_arg(ap, unsigned int));
	else if (arg_type == 'x' || arg_type == 'X')
                args_amount += pf_puthexadec(va_arg(ap, unsigned int), arg_type);
	else if (arg_type == '%')
		args_amount += write(1, "%", 1);
	return (args_amount);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		bytes_printed;

	i = 0;
	bytes_printed = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			bytes_printed += def_function(ap, format[i + 1]);
			i += 2;
		}
		else
		{
			bytes_printed += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (bytes_printed);
}
/*
int	main(void)
{
	#include <stdio.h>

	int		elements_ft;
	int		elements_original;
	char		c;
	char		*s;
	int		d;
	int		i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	upperx;

	c = 'a';
	s = "Hello, World!";
	d = 14;
	i = 21;
	u = 3;
	x = 14;
	upperx = 14;
	elements_ft = 0;
	elements_original = 0;
	printf("\n************* COMPARISON TESTS *************\n");
	ft_printf("\n-------------------- Test0: c --------------------\n");
	ft_printf("ft_printf: ");
	elements_ft = ft_printf("%c", c);
	ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
	printf("   printf: ");
	elements_original = printf("%c", c);
	printf(" >>> Total printed: %d element(s)\n\n", elements_original);

	ft_printf("\n-------------------------- Test1: s --------------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%s", s);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%s", s);
        printf(" >>> Total printed: %d element(s)\n\n", elements_original);

	ft_printf("\n--------------------------- Test2: p ---------------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%p", &s);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%p", &s);
        printf(" >>> Total printed: %d element(s)\n\n", elements_original);

	ft_printf("\n-------------------- Test3: d --------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%d", d);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%d", d);
        printf(" >>> Total printed: %d element(s)\n", elements_original);

	ft_printf("\n--------------------- Test4: i ---------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%i", i);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%i", i);
        printf(" >>> Total printed: %d element(s)\n", elements_original);

	ft_printf("\n-------------------- Test5: u --------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%u", u);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%u", u);
        printf(" >>> Total printed: %d element(s)\n", elements_original);

	ft_printf("\n-------------------- Test6: x --------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%x", x);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%x", x);
        printf(" >>> Total printed: %d element(s)\n", elements_original);

	ft_printf("\n-------------------- Test7: X --------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%X", upperx);
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%X", upperx);
        printf(" >>> Total printed: %d element(s)\n", elements_original);

	ft_printf("\n--------------------- Test8: % ---------------------\n");
	ft_printf("ft_printf: ");
        elements_ft = ft_printf("%%");
        ft_printf(" >>> Total printed: %d element(s)\n\n", elements_ft);
        printf("   printf: ");
        elements_original = printf("%%");
        printf(" >>> Total printed: %d element(s)\n\n", elements_original);
	return (0);
}*/
