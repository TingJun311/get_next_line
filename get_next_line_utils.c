/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:55:32 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/21 16:35:28 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[k])
		res[i++] = s2[k++];
	res[i] = '\0';
	return (res);
}

int	detect_line(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*init_cache(void)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * 1);
	buffer[0] = 0;
	return (buffer);
}

void	replace_null(char *str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		str[i] = 0;
		i++;
	}
}
