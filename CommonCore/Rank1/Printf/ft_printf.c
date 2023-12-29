/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:07:14 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 19:57:14 by tsoares-         ###   ########.fr       */
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
		args_amount += pf_putpercent();
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
//
//int	main(void)
//{
//	#include <stdio.h>
//
//	int	elements_ft;
//	int	elements_original;
//	char	*s;
//
//	s = "Hello, World";
//	elements_ft = 0;
//	elements_original = 0;
//	printf("\n------- FT_PRINTF test -------\n");
	/*elements_ft = ft_printf("%s", elements_ft);
	ft_printf("\nTeste0: %c\nTeste1: %s\nTeste2: %p\n
                Teste3: %d\nTeste4: %i\nTeste5: %u\n
                Teste6: %x\nTeste7: %X\nTeste8:%%\n\n",
		'a', s, &s,
		7, 21, 3,
		7, 21);*/
//	elements_ft = ft_printf("%c", 'z');
//	ft_printf("\nTotal printed: %d element(s)\n\n", elements_ft); //changes to ft_printf function when %d is defined
//
//	printf("--------- PRINTF test ---------\n");
//	elements_original = printf("%d", elements_original);
//	printf("\nTeste0: %c\nTeste1: %s\nTeste2: %p\n"
//                "Teste3: %d\nTeste4: %i\nTeste5: %u\n"
//                "Teste6: %x\nTeste7: %X\nTeste8:%%\n\n",
//                'a', s, &s,
//                7, 21, 3,
//                7, 21);
//	elements_original = printf("%c", 'z');
//	printf("\nTotal printed: %d element(s)\n\n", elements_original);
//	return (0);
//}
