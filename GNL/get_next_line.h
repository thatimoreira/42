/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:19:12 by tsoares-          #+#    #+#             */
/*   Updated: 2024/02/02 05:58:03 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h> // to use ssize_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *str1, char const *str2);
char		*ft_substr(const char *stg, unsigned int start, size_t len);
char		*get_next_line(int fd);

#endif
