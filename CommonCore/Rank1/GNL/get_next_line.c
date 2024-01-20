/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:42:16 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/19 21:39:17 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	read_lines(int fldesc, char *buf)
{
	static char	*temp_buffer;

	// ler o fd até achar '\n' ou '\0'
	// copiar o conteúdo da linha -> copy_line()
}

int	*get_next_line(int fd)
{
	char		*buffer;
	size_t		chars_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = read_lines(fd, &buffer);
	// liberar a memória após preencher a linha

	// 
}
