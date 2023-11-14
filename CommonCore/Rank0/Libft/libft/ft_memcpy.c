/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:11 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/14 19:08:05 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return ((void *)dest);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	source[] = "Qualquer coisa";
	char	destination[] = "nguhdfgjfdgijdfjgodifjgoiç";
	size_t	num;

	num = 13;
	ft_memcpy(destination, source, num);
	printf("%s\n", destination);
	return (0);
}*/
