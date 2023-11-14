/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:50:46 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 18:04:42 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	if (*tempdest > *tempsrc)
	{
		while (n-- > 0)
			tempdest[n] = tempsrc[n];
	}
	else if (*tempdest < *tempsrc)
	{
		while (i < n)
		{
			tempdest[i] = tempsrc[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	source[] = "Ubuntu";
	size_t	num;

	num = 3;
	ft_memmove(source + 2, source, num);
	printf("%s\n", source);
	return (0);
}*/
