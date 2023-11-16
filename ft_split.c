/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 04:47:34 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/14 17:29:48 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *full_str, char delimiter)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (full_str[i])
	{
		while (full_str[i] == delimiter)
			i++;
		if (!full_str[i])
			count++;
		while (full_str[i] && full_str[i] != delimiter)
			i++;
	}
	return (count);
}

static char	*ft_malloc_word(char const *str, char **words, char c_del)
{
	char	*word;
	size_t	word_len;
	size_t	i;

	word_len = 0;
	i = 0;
	while (str[word_len] && str[word_len] != c_del)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
	{
		while (words[i])
			free(words[i++]);
		free(words);
		return (NULL);
	}
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
	arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	str_pos = 0;
	arr_pos = 0;
	while (s[str_pos])
	{
		while (s[str_pos] == c)
			str_pos++;
		if (s[str_pos])
		{
			arr[arr_pos] = ft_malloc_word(&s[str_pos], arr, c);
			arr_pos++;
			while (s[str_pos] && s[str_pos] != c)
				str_pos++;
		}
	}
	arr[arr_pos] = '\0';
	return (arr);
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
