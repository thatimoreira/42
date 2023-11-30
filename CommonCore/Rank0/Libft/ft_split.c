/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:47:34 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/21 07:24:58 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nwords(char const *full_str, char delimiter)
{
	int		num_words;
	size_t	i;

	i = 0;
	num_words = 0;
	while (full_str[i])
	{
		if (full_str[i] != delimiter)
		{
			num_words++;
			while (full_str[i] != delimiter)
				i++;
		}
		else if (full_str[i] == delimiter)
			i++;
	}
	return (num_words);
}

static char	*ft_malloc_word(char const *str, char c_del)
{
	char	*word;
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c_del)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word_len = 0;
	while (str[word_len] && str[word_len] != c_del)
	{
		word[word_len] = str[word_len];
		word_len++;
	}
	word[word_len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_pos;
	size_t	str_pos;

	if (!s)
		return (NULL);
	arr = (char **)malloc((ft_nwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	str_pos = 0;
	arr_pos = 0;
	while (s[str_pos])
	{
		if (s[str_pos] != c)
			arr[arr_pos++] = ft_malloc_word(&s[str_pos], c);
		if (!arr[arr_pos - 1])
			return (NULL);
		while (s[str_pos] && s[str_pos] != c)
			str_pos++;
		str_pos++;
	}
	arr[arr_pos] = NULL;
	return (arr);
}
/*
int	main(void)
{
	#include <stdio.h>

	//char	const *str;
	//char	character;
	char	**splitted_str;
	int	i;


	//str = "Fui ao mercado comprar cafeh";
	//character = 'a';
	splitted_str = ft_split("  tripouille  42  ", ' ');
	//splitted_str = ft_split("\0abc\n\0def\0\nghi", '\0');
	i = 0;
	while (splitted_str[i])
	{
		printf("%s\n", splitted_str[i]);
		i++;
	}
	free(splitted_str);
	return (0);
}*/
