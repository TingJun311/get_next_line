#include "get_next_line_bonus.h"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

static void	display(int call, char *str, int file)
{
	printf(GRN);
	printf("(%dst call)", call);
	printf(RESET);
	printf(" in file");
	printf(GRN);
	printf("[%d]", file);
	printf(RESET);
	printf(": %s\n", str);
}

static int read_different_files(int fd, int fd2, int fd3, int call)
{
	char		*res;
	static int	finished;
	int		file;

	file = 1;
	finished = 0;
	res = get_next_line(fd);
	if (res)
	{
		display(call, res, file);
		free(res);
	}
	else
		finished++;
	file++;
	res = get_next_line(fd2);
	if (res)
	{
		display(call, res, file);
		free(res);
	}
	else
		finished++;
	file++;
	res = get_next_line(fd3);
	if (res)
	{
		display(call, res, file);	
		free(res);
	}
	else
		finished++;
	return (finished);
}

int	main(int ac, char **av)
{
	int 	fd[4];
	int	call;
	int	f_call;
	
	if (ac == 4)
	{
		call = 1;
		f_call = 1;
		for(int i = 0; i < 3; i++)
			fd[i] = open(av[i + 1], O_RDONLY);
		while (call != 3)
			call = read_different_files(fd[0], fd[1], fd[2], f_call++);
		write(1, "OK!\n", 4);
		for(int i = 0; i < 3; i++)
			close(fd[i]);
	}
	else
		write(1, "Must have 3 files to run the program\n", 37);

	return (0);
}
