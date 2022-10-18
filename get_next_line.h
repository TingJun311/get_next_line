#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int		ft_check_new_line(const char *s, char c);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strtrim_front(char *buffer, char *temp);

#endif
