/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:04:45 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/17 22:32:57 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_del_join(char *buffer, char *temp, int index)
{
	
}

static char	*ft_get_line(char *str)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	if (str == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 2));
	while (k < i)
	{
		ptr[k] = str[k];
		k++;	
	}
	if (ptr[k] != '\n')
		ptr[k++] = '\n';
	ptr[k] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static	char 	*buffer;
	char			*temp;
	int				nbyte_read;
	size_t			k;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = "";
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	nbyte_read = 1;
	k = 0;
	while (nbyte_read > 0)
	{
		nbyte_read = read(fd, temp, BUFFER_SIZE);
		temp[nbyte_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (ft_check_new_line(buffer, '\n'))
			break;
	}
	temp = ft_get_line(buffer);
	k = ft_strtrim_front(buffer, temp);
	buffer += k;
	return (temp);
}

int	main(int ac, char **av)
{
	int	fd;
	(void)ac;
	(void)av;
	//char s1[100] = "This is a string\ndededmmm dsda";
	//char s2[100] = "This is a string\n hiskljdsa dsdad";
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		printf("1st call: %s\n", get_next_line(fd));
		printf("2st call: %s\n", get_next_line(fd));
		close(fd);
	}
	else
		write(1, "Empty text file", 15);
	return (0);
}
