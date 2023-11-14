/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:57:21 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 20:15:40 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	#include <stdio.h>

	char		*str_dest;
	const char	*str_src;
	size_t		dest_size;
	size_t		total_length;

	str_src = "Yolo!! :)";
	dest_size = 6;
	str_dest = (char *)calloc(dest_size, sizeof(char));
	if (str_dest == NULL)
		return (-1);
	total_length = ft_strlcpy(str_dest, str_src, dest_size);
	printf("str_dest = %s\n", str_dest);
	printf("Total length: %lu\n", total_length);
	free(str_dest);
	return (0);
}*/
