/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:59:10 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 19:07:25 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temps;
	size_t			i;

	temps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temps[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	#include <stdio.h>

	char	str[] = "Erikah Badu";
	size_t	num;
	
	num = 4;
	ft_bzero(str, num);
	return (0);
}*/
