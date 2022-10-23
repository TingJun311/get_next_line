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

static char	*ft_join_free(char *cache, char *temp)
{
	char	*new_cache;

	if (cache == NULL)
		return (NULL);
	new_cache = ft_strjoin(cache, temp);
	free(cache);
	cache = NULL;
	return (new_cache);
}

static char	*scan_file(int fd, char *cache)
{
	char	*temp;
	int		read_char;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (cache == NULL)
		cache = init_cache();
	read_char = 1;
	while (read_char > 0)
	{
		replace_null(temp);
		read_char = read(fd, temp, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[BUFFER_SIZE] = '\0';
		cache = ft_join_free(cache, temp);
		if (detect_line(temp))
			break ;
	}
	free(temp);
	return (cache);
}

static char	*retrieve_line(char *str)
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

static char	*trim_front(char *str)
{
	char	*new_cache;
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
	new_cache = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	k = 0;
	while (str[i])
		new_cache[k++] = str[i++];
	new_cache[k] = '\0';
	free(str);
	str = NULL;
	return (new_cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cache = scan_file(fd, cache);
	if (!cache[0])
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	temp = retrieve_line(cache);
	if (!temp[0])
	{
		free(temp);
		return (NULL);
	}
	cache = trim_front(cache);
	return (temp);
}
