#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void factorize(char *);

/**
 * main - Factorize all numbers listed in a file and
 *	displays them to stdout
 *
 *  @ac: arg num
 *  @av: arg arr
 *
 *  Return: Always 0
 */
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
		factorize(line);


	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

/**
 * factorize - Factorize a number
 * @buff: A buffer holding the number
 */
void factorize(char *buff)
{
	int num, i;

	num = atoi(buff);

	for (i = 2; i < num; i++)
		if (!(num % i))
		{
			printf("%d=%d*%d\n", num, num / i, i);
			return;
		}
}
