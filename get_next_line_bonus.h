/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:48:24 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/21 19:48:49 by ctingjun         ###   ########.fr       */
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

int		ft_check_line(const char *str);

char	*ft_calloc(void);

void	ft_clean(char *str);

#endif
