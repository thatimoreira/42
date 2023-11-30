/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:19:26 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/21 07:43:46 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	temp_c;
	size_t			length;

	temp_c = (unsigned char)c;
	length = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + length));
	while (length > 0)
	{
		length--;
		if (s[length] == c)
			return ((char *)(s + length));
	}
	return (NULL);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	*source;
	int		letter;
	char	*lastl;

	source = "Have a nice day";
	letter = 'a';
	lastl = ft_strrchr(source, letter);
	printf("%s\n", lastl);
	return (0);
}*/
