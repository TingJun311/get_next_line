/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:07:01 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/21 16:34:43 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *buffer, char *temp)
{
	char	*new_buffer;

	if (buffer == NULL)
		return (NULL);
	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	buffer = NULL;
	return (new_buffer);
}

char	*ft_get_line(int fd, char *buffer)
{
	char	*temp;
	int		read_char;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc();
	read_char = 1;
	while (read_char > 0)
	{
		ft_clean(temp);
		read_char = read(fd, temp, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[BUFFER_SIZE] = '\0';
		buffer = ft_join_free(buffer, temp);
		if (ft_check_line(temp))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*ft_retriv_line(char *str)
{
	char	*ptr;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1 + (str[i] == '\n')));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strim_front(char *str)
{
	char	*new_buffer;
	size_t	i;
	size_t	k;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	new_buffer = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	k = 0;
	while (str[i])
		new_buffer[k++] = str[i++];
	new_buffer[k] = '\0';
	free(str);
	str = NULL;
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_get_line(fd, buffer);
	if (!buffer[0])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	temp = ft_retriv_line(buffer);
	if (!temp[0])
	{
		free(temp);
		return (NULL);
	}
	buffer = ft_strim_front(buffer);
	return (temp);
}

//int	main(int ac, char **av)
//{
//	int fd;
//	(void)ac;
//	(void)av;
//
//	if (ac > 1)
//	{
//		fd = open(av[1], O_RDONLY);
//		printf("1st call: %s", get_next_line(fd));
//		printf("2st call: %s", get_next_line(fd));
//		printf("3st call: %s", get_next_line(fd));
//		printf("4st call: %s", get_next_line(fd));
//		printf("5st call: %s", get_next_line(fd));
//		printf("6st call: %s", get_next_line(fd));
//		printf("7st call: %s", get_next_line(fd));
//		printf("8st call: %s", get_next_line(fd));
//		printf("9st call: %s", get_next_line(fd));
//		printf("10st call: %s", get_next_line(fd));
//		close(fd);
//	}
//	else
//		write(1, "Empty", 5);
//	return (0);
//}
