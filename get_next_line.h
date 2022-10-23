/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:10:30 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/21 16:28:13 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *s1, char *s2);

int	detect_line(const char *str);

char	*init_cache(void);

void	replace_null(char *str);

#endif
