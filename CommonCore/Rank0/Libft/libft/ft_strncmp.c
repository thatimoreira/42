/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:58:47 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 15:13:58 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] - str2[i] == 0)
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>

	const char	*st1;
	const char	*st2;
	size_t		i;
	int			compare;

	i = 6;
	st1 = "Hoje eh dia de...";
	st2 = "Hoje nao eh dia de...";
	compare = ft_strncmp(st1, st2, i);
	printf("%d\n", compare);
	return (0);
}*/
