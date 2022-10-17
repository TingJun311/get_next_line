/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctingjun <ctingjun@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:20:59 by ctingjun          #+#    #+#             */
/*   Updated: 2022/10/17 22:19:50 by ctingjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_new_line(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	if (s2 == NULL)
		return ((char *)s1);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k])
		ptr[i++] = s2[k++];
	ptr[i] = '\0';
	return (ptr);	
}


size_t	ft_strtrim_front(char *buffer, char *temp)
{
	size_t	i;

	i = 0;
	if (buffer == NULL || temp == NULL)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] == temp[i] && temp[i] != '\n')
		i++;
	return (i);
}
