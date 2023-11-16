/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:48:36 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 10:55:32 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	#include <stdio.h>

	const char	*str;
	size_t		str_len;

	str = "My world is not determined on the price of my clothes";
	str_len = ft_strlen(str);
	printf("%ld\n", str_len);
	return (0);
}*/
