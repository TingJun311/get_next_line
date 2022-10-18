#include "get_next_line.h"


//int	main(int ac, char **av)
//{
//	int	fd;
//	int	reading;
//	//char buffer[SIZE];
//	int	i;
//
//	(void)ac;
//	(void)av;
//	(void)i;
//	if (ac > 1)
//	{
//		i = 0;
//		fd = open(av[1], O_RDONLY);
//	//	reading = read(fd, buffer, SIZE);
//	//	buffer[reading] = '\0';
//	//	printf("%s\n", buffer);
//	//	printf("Read: %d", reading);
//	//	printf("------------------------\n");
//	//	while (buffer[i])
//	//	{
//	//		if (buffer[i] == '\n')
//	//			printf("Founded");
//	//		printf("%c ", buffer[i]);
//	//		i++;
//	//	}
//		printf("1st call: %s\n", get_next_line(fd));
//		printf("Second call: %s\n", get_next_line(fd));
//		close(fd);
//	}
//	else
//		write(1, "Empty file", 10);
//	return (0);
//}
