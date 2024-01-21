/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:42:16 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/21 01:09:22 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_line(char *temp_str)
{
	size_t	count;
	char	*after_n;
	size_t	len;

	count = 0;
	len = 0;
	while (temp_str[count] != '\n' && temp_str[count])
		count++;
	if (temp_str[count] == '\0')
		return (NULL);
	len = ft_strlen(temp_str) - count;
	after_n = ft_substr(temp_str, count + 1, len); // the +1 is to skip the '\n'
	if (*after_n == '\0') // condition used in case the '\n' is the only char of the str
		free(after_n);
	temp_str[count + 1] = '\0';
	return (after_n); // return only the chars that are after the '\n' to save them inside the static variable
}

static char	*read_lines(int fldesc, char *buf, static char *temp_buf)
{
	ssize_t	chars_read;
	char	*backup;

	chars_read = 1;
	while (chars_read != 0)
	{
		chars_read = read(fldesc, buf, BUFFER_SIZE);
		if (chars_read < 0)
			return (NULL);
		if (chars_read == 0)
			break ;
		buf[chars_read] = '\0';
		if (!temp_buf)
			temp_buf = ft_strdup("");
		backup = temp_buf;
		temp_buf = ft_strjoin(backup, buf);
		free(backup);
		if (find_n(temp_buf, '\n') == '\n')
			break ;
	}
	return (temp_buf);
}

char	*get_next_line(int fd)
{
	static char	*line_read;
	char		*buffer;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line_read = read_lines(fd, buffer, line_read);
	free(buffer);
	if (!current_line)
		return (NULL);
	line_read = check_line(current_line);
	return (current_line);
}

int	main(void)
{
	#include <stdio.h>
	#include <fcntl.h> //to use open function

	int	file_desc;
	char	*current_ln;
	int	i;

	i = 0;
	fd = open("fd", O_RDONLY);
	while (i < BUFFER_SIZE)
	{
		current_ln = get_next_line(file_desc);
		printf("%s", current_ln);
		free(current_ln);
		i++;
	}
	return (0);
}
