/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:19:21 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 17:07:47 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && little_len <= len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	*bigstr;
	char	*littlestr;
	size_t	length;
	char	*localize;

	bigstr = "Paralelepipedo";
	littlestr = "lele";
	length = 8;
	localize = ft_strnstr(bigstr, littlestr, length);
	printf("%s\n", localize);
	return (0);
}*/
