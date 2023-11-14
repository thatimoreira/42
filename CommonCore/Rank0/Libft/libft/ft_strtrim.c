/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:54:30 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/14 14:59:03 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimstr;
	size_t	i;

	start = 0;
	end = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	trimstr = (char *)malloc((end - start + 1) * sizeof(char));
	if (trimstr == NULL)
		return (NULL);
	while (start < end)
		trimstr[i++] = s1[start++];
	trimstr[i] = '\0';
	return (trimstr);
}
/*
int     main(void)
{
	#include <stdio.h>

	char const *str1;
	char const *set;
	char    *trimmed_str;

	str1 = "abcabJuntos somos mais fortesaabc";
	set = "aabc";
	trimmed_str = ft_strtrim(str1, set);
	printf("%s\n", trimmed_str);
	free(trimmed_str);
	return (0);
}*/
