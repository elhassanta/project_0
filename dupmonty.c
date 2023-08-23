//#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int checkline(char **line)
{
	char *str3 = *line;
	while (str3[0] == ' ' || str3[0] == '\t')
		str3 = str3 + 1;
	if (str3[0] == '\0')
		return (1);
	char *dupline = strdup(str3);
	char *str[3];
	const char *push = "push";
	const char *pall = "pall";
	int i = 0, num;

	str[i] = strtok(dupline," \t");

	while (str[i])
	{
		i++;
		str[i] = strtok(NULL, " \t");
	}

	if (i == 0)
	{

		free(dupline);
		return (1);
	}
	else if (i == 1)
	{
		const char *str1 = str[0];

		if (strcmp(str1, pall) == 0)
		{

			free(dupline);
			return (1);
		}
		free(dupline);
		return (0);
	}
	else if (i == 2)
	{
		const char *str1 = str[0];
		if (!strcmp(str1, push))
		{
			num = atoi(str[1]);
			if (num == 0  && (str[1][0] != '0'))
			{
				free(dupline);
				return (2);
			}

			free(dupline);
			return (1);
		}
		free(dupline);
		return(0);
	}
	else
	{

		free(dupline);
		return (0);
	}
}
int main(int argc, char **argv)
{
	int i = 0, fd;
	FILE *file_stream;
	char *line = NULL;
	size_t bytes = 0;
	ssize_t len = 0;
	char *dupline = NULL;
	ssize_t number_of_line = 1;
	char str_n_of_line[20];

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n",sizeof("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
	else
	{
		file_stream = fopen(argv[1], "r");
		if (file_stream == NULL)
		{
			write(2, "Error: Can't open file ", sizeof("Error: Can't open file "));
			write(2, argv[1], strlen(argv[1]));
			write(2, "\n", sizeof("\n"));
		}

		while ((bytes = getline(&line, &len, file_stream)) != -1)
		{
			snprintf(str_n_of_line, sizeof(str_n_of_line), "%d", number_of_line);

			len = strlen(line);
			dupline = strdup(line);
			dupline[len - 1] = '\0';
			printf("this is the line %d\n", number_of_line);
			printf("-----\n");
			int check = checkline(&dupline);


			if (check == 0)
			{
				write(2, "check get an error\n", sizeof("check get an error\n"));
				free(line);
				free(dupline);
				exit(EXIT_FAILURE);
			}
			else if (check == 1)
			{
				printf("-->line is : %s ", dupline);
				printf("-len is : %d\n", len);

			}
			else if (check == 2)
			{

				write(2, "L",2);
				write(2, str_n_of_line, sizeof(str_n_of_line));
				write(2, ": usage: push integer\n",sizeof(": usage: push integer\n"));
				free(line);
				free(dupline);
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("** this condition 3\n");
			}
			printf("-----\n");
			number_of_line++;
		}
		free(line);
	}
	return (0);
}
