#include "monty.h"

FILE *open_file(char *str, char *mod)
{
	FILE *file_stream = fopen(str, mod);
	if (file_stream == NULL)
	{
		write(2, "Error: Can't open file ", sizeof("Error: Can't open file "));
		write(2, str, strlen(str));
		write(2, "\n", sizeof("\n"));
		exit(EXIT_FAILURE);
	}
	return (file_stream);
}
void regular_errror(char *str_n_of_line, char *line)
{
	write(2, "L", sizeof("L"));
	write(2, str_n_of_line, strlen(str_n_of_line));
	write(2, ": unknown instruction ", sizeof(": unknown instruction "));
	write(2, line, strlen(line));
	write(2, "\n", 2);
}
void push_error(char *str_n_of_line)
{
	write(2, "L",2);
	write(2, str_n_of_line, strlen(str_n_of_line));
	write(2, ": usage: push integer\n",sizeof(": usage: push integer\n"));
	exit(EXIT_FAILURE);
}
void error_n_arguments()
{
	write(2, "USAGE: monty file\n",sizeof("USAGE: monty file\n"));
	exit(EXIT_FAILURE);
}
int main(int argc, char **argv)
{
	int i = 0;
	FILE *file_stream;
	char *mod = "r";
	char *line = NULL;
	size_t bytes = 0;
	ssize_t len = 0;
	char *dupline = NULL;
	unsigned int number_of_line = 1;
	char str_n_of_line[20];

	if (argc != 2)
	{
		error_n_arguments();
	}
	else
	{
		file_stream = open_file(argv[1], mod);

		while ((bytes = getline(&line, &len, file_stream)) != -1)
		{
			snprintf(str_n_of_line, sizeof(str_n_of_line), "%u", number_of_line);

			len = strlen(line);
			dupline = strdup(line);
			dupline[len - 1] = '\0';



			int check = checkline(&dupline);

			if (check == 0)
			{
				free(line);
				regular_errror(str_n_of_line ,dupline);
				free(dupline);
				exit(EXIT_FAILURE);
			}
			else if (check == 1)
			{
				/********************** add code right here *********************/
				printf("-len is : %d\n", len);
				free(dupline);
			}
			else if (check == 2)
			{
				free(line);
				free(dupline);
				push_error(str_n_of_line);
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
