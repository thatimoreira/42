/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:23:28 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/15 01:50:59 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (size == 0 || !*dst || !*src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	while ((dst_len + i + 1) < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	dest[] = "I learned to love myself unconditionally";
	char	source[] = "\nBecause I am a queen";
	size_t dest_size;
	size_t	total_len;

	dest_size = sizeof(dest);
	total_len = ft_strlcat(dest, source, dest_size);
	printf("%s %s\n", dest, source);
	printf("Total length: %lu\n", total_len);
	return (0);
}*/
