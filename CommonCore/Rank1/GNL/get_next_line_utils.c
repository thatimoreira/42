/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:52:08 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/27 22:32:14 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst = ft_strcpy(dst, str);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s_pos;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s_pos = 0;
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[s_pos++];
	s_pos = 0;
	while (s2[s_pos])
		str[i++] = s2[s_pos++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *stg, unsigned int start, size_t len)
{
	char	*substr;
	size_t	end_substr;
	size_t	stg_len;
	size_t	i;

	if (!stg)
		return (NULL);
	stg_len = ft_strlen(stg);
	i = 0;
	if (stg_len <= start)
		return (ft_strdup(""));
	if (stg_len < start + len)
		end_substr = stg_len;
	else
		end_substr = start + len;
	substr = (char *)malloc((end_substr - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < end_substr)
		substr[i++] = stg[start++];
	substr[i] = '\0';
	return (substr);
}

char	*find_n(const char *st, int c)
{
	size_t	i;
	char	*temp_s;

	i = 0;
	temp_s = (char *)st;
	while (temp_s[i])
	{
		if (temp_s[i] == (char)c)
			return ((char *)&temp_s);
		i++;
	}
	return (NULL);
}
