/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:35:59 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 17:38:53 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*replace;

	replace = s;
	while (n-- > 0)
		replace[n] = c;
	return (s);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	str[] = "Ubuntu";
	int	letter;
	size_t	num;
	
	letter = '>';
	num = 4;
	ft_memset(str, letter, num);
	printf("%s\n", str);
	return (0);
}*/
