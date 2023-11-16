/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:07:58 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/15 16:08:38 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	end_substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len < start + len)
		end_substr = s_len;
	else
	{
		end_substr = start + len;
		substr = (char *)malloc((end_substr - start + 1) * sizeof(char));
	}
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (start < end_substr)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/*int	main(void)
{
	#include <stdio.h>

	char const	*str = "Role de cria";
	unsigned int	st = 8;
	size_t		length = 4;
	char		*sub_str;
	int		i;

	sub_str = ft_substr(str, st, length);
	i = 0;
	printf("%s\n", sub_str);
	return (0);
}*/
