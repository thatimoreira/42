/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:51:50 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/21 07:30:31 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp_c;
	size_t			i;

	i = 0;
	temp_c = (unsigned char)c;
	while (s[i] != temp_c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
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
