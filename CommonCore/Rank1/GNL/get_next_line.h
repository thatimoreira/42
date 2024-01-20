/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:19:12 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/18 18:47:00 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GENT_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> //to use open function
#include <types.h> // to use ssize_t

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 84
# endif

char	*get_next_line(int fd);

# endif
