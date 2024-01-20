/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:42:16 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/20 00:16:56 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char     read_lines(int fldesc, char *buf, static char ***temp_buf)
{
        ssize_t         chars_read;

        // ler o fd até achar '\n' ou '\0'
        // copiar o conteúdo da linha -> copy_line()
}

int     *get_next_line(int fd)
{
        static char     **temp_buffer;
        char            *buffer;
        char            *line_read

        if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
                return (NULL);
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
                return (NULL);
        line_read = read_lines(fd, &buffer, &temp_buffer);
        // liberar a memória após preencher a linha
        free(buffer);


        // 
}
