/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:47:34 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/14 17:36:04 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_of_substr(char const *full_str, char delimiter)
{
	int	qt_substr;
	int	qt_delimiter;
	int	i;

	qt_substr = 0;
	qt_delimiter = 0;
	i = 0;
	while (full_str[i])
	{
		if (full_str[i++] == delimiter)
			qt_delimiter++;
	}
	if (full_str[0] == delimiter && full_str[i--] == delimiter)
		qt_substr = qt_delimiter - 1;
	else if (full_str[0] == delimiter || full_str[i--] == delimiter)
		qt_substr = qt_delimiter;
	else
		qt_substr = qt_delimiter + 1;
	return (qt_substr);
}

static char	**ft_malloc_substr_arr(size_t n_substrs)
{
	char	**substr_arr;

	substr_arr = (char **)malloc((n_substrs + 1) * sizeof(char *));
	if (substr_arr == NULL)
		return (NULL);
	return (substr_arr);
}

static char	**ft_malloc_substrings(char **arr_subs, char const *str, char c_del)
{
	int		arr_pos;
	int		sub_pos;
	size_t	sub_len;

	arr_pos = 0;
	sub_pos = 0;
	sub_len = 0;
	while (str[sub_pos])
	{
		while (str[sub_pos] && str[sub_pos] != c_del)
		{
			sub_len++;
			sub_pos++;
		}
		arr_subs[arr_pos] = (char *)malloc((sub_len + 1) * sizeof(char));
		if (arr_subs[arr_pos] == NULL)
			return (NULL);
		arr_subs[arr_pos][sub_len] = '\0';
		arr_pos++;
		sub_pos++;
	}
	return (arr_subs);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_substrs;
	char	**subs_arr;
	size_t	subarr_pos;
	size_t	substr_pos;
	size_t	substr_len;

	num_substrs = ft_num_of_substr(s, c);
	subs_arr = ft_malloc_substr_arr(num_substrs);
	if (subs_arr == NULL)
		return (NULL);
	subs_arr = ft_malloc_substrings(subs_arr, s, c);
	subs_arr[num_substrs] = '\0';
	subarr_pos = 0;
	substr_pos = 0;
	while (subs_arr[subarr_pos])
	{
		substr_len = 0;
		while (s[substr_pos] && s[substr_pos] != c)
			subs_arr[subarr_pos][substr_len++] = s[substr_pos++];
		subs_arr[subarr_pos][substr_len] = '\0';
		subarr_pos++;
		substr_pos++;
	}
	return (subs_arr);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	const *str;
	char	character;
	char	**splitted_str;
	int	i;
        

	str = "Fui ao mercado comprar cafeh";
	character = 'a';
	splitted_str = ft_split(str, character);
	i = 0;
	while (splitted_str[i])
	{
		printf("%s\n", splitted_str[i]);
		free(splitted_str[i]);
		i++;
	}
	free(splitted_str);
	return (0);
}*/
