#include "get_next_line_bonus.h"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

static void display (int call, char *str, int file)
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

static int read_files(int files[], int  q_file, int  call)
{
	static int 	finished;
	char		*res;
	
	finished = 0;
	for (int i = 0; i < q_file; i++)
	{
		res = get_next_line(files[i]);
		display(call, res, i + 1);
		if (res)
			free(res);
		else
			finished++;
	}
	return (finished);
}

int	main(int ac, char **av)
{
	int 	fd[8192], call, f_call, files;
	
	if (ac > 1)
	{
		files = 0;
		while (av[files + 1])
			files++;
		printf("%d\n", files);
		call = 0;
		f_call = 1;
		for(int i = 0; i < files; i++)
			fd[i] = open(av[i + 1], O_RDONLY);
		while (call != files)
			call = read_files(fd, files, f_call++);
		write(1, "OK!\n", 4);
		for(int i = 0; i < files; i++)
			close(fd[i]);
	}
	else
		write(1, "Must have 3 files to run the program\n", 37);

	return (0);
}
