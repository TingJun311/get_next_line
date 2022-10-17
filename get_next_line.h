/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:51:46 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/17 22:20:13 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

char	*get_next_line(int fd);

int		ft_check_new_line(const char *s, char c);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strtrim_front(char *buffer, char *temp);

#endif

