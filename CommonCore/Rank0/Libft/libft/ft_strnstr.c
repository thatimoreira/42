/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:19:21 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/15 03:16:07 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	if (little_len == NULL || little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	i = 0;
	while (index <= len - little_len)
	{
		if (!big[i])
			return (NULL);
		if (ft_strncmp((big + i), little, little_len) == 0)
			return ((char *)(big + i));
		i++;
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
