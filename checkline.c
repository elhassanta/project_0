#include "monty.h"
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
	if (!strcmp(str[0], pall))
	{
		free(dupline);
		return (1);
	}
	else if (!strcmp(str[0], push))
	{
		if (str[1] == NULL)
		{
			free(dupline);
			return (2);
		}
		num = atoi(str[1]);
		if (num == 0  && (str[1][0] != '0'))
		{
			free(dupline);
			return (2);
		}
		free(dupline);
		return (1);
	}
	else
	{

		free(dupline);
		return (0);
	}
}
