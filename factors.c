#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int ac, char **av)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	long long flag = 1, div, rest, number, counter;
	ssize_t nread;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (!stream)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		flag = 1, div = 2;
		number = atoll(line);
		while (flag)
		{
			rest = number % div;
			if (!rest)
			{
				counter = number / div;
				printf("%lld=%lld*%lld\n", number, counter, div);
				flag = 0;
			}
			div++;
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
