/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:51:50 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 15:07:26 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	*source;
	int		a;
	char	*l;

	source = "Bom dia!";
	a = 'm';

	printf("Test 1: ");
	l = ft_strchr(source, a);
	printf("%s\n", l);

	printf("Test 2: ");
	l = ft_strchr(source, '\0');
	printf("%s\n", l);
	return (0);
}*/
