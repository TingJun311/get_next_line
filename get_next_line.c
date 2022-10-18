
#include "get_next_line.h"

static char	*ft_get_line(char *str)
{
	char	*ptr;
	size_t	i;
	size_t	k;

	i = 0;
	if (!str[i])
		return (NULL);
	k = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 2));
	while (*str && str[k] != '\n')
	{
		ptr[k] = str[k];
		k++;	
	}
	if (ptr[k] == '\n' && ptr[k])
		ptr[k++] = '\n';
	ptr[k] = '\0';
	return (ptr);
}

static	char *read_line(char *buffer, int fd)
{
	char 	*new_buffer;
	int		nbyte_read;

	nbyte_read = 1;
	new_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new_buffer == NULL)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (buffer == NULL)
			return (NULL);
		buffer[0] = 0;
	}
	while (nbyte_read > 0)
	{
		nbyte_read = read(fd, new_buffer, BUFFER_SIZE);
		if (nbyte_read == -1)
		{
			free(new_buffer);
			return (NULL);
		}
		new_buffer[nbyte_read] = '\0';
		buffer = ft_strjoin(buffer, new_buffer);
		if (ft_check_new_line(new_buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static	char 	*buffer;
	char			*temp;
	size_t			k;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(buffer, fd);
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
		printf("3st call: %s\n", get_next_line(fd));
		printf("4st call: %s\n", get_next_line(fd));
		printf("5st call: %s\n", get_next_line(fd));
		printf("6st call: %s\n", get_next_line(fd));
		printf("7st call: %s\n", get_next_line(fd));
		printf("8st call: %s\n", get_next_line(fd));
		printf("9st call: %s\n", get_next_line(fd));
		printf("10st call: %s\n", get_next_line(fd));
		close(fd);
	}
	else
		write(1, "Empty text file", 15);
	return (0);
}
