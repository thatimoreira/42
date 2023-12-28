/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:16:20 by tsoares-          #+#    #+#             */
/*   Updated: 2023/12/28 07:08:05 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		pf_putchar(int c);
int		pf_putstr(char *str);
size_t	pf_strlen(const char *str);
int		pf_putptr(unsigned long long ptr);
int		pf_puthexadec(unsigned int num, format);

#endif
