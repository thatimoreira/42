/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:16:20 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/04 19:55:10 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int		ft_printf(const char *format, ...);
int		pf_putchar(int c);
int		pf_putstr(char *str);
size_t	pf_strlen(const char *str);
int		pf_putptr(void *ptr);
int		pf_puthexadec(unsigned int num, const char format);
int		pf_putnbr(int num);
int		pf_put_uint(unsigned int num);
size_t	pf_numlen(unsigned long long num);

#endif
