#include "get_next_line.h"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int	main(int ac, char **av)
{
        int 	fd;
	int	call;
        char    *res;

        if (ac > 1)
        {
                fd = open(av[1], O_RDONLY);
		call = 1;
		while (1)
		{
                	res = get_next_line(fd);
			printf(GRN);
			printf("(%dst call)", call);
			printf(RESET);
			printf(": %s\n", res);
			free(res);
			call++;
			if (res == NULL)
				break ;
		}
                close(fd);
        }
        else
                write(1, "Empty file\n", 11);
        return (0);
}
