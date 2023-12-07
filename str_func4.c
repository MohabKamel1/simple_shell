#include "shell.h"

/**
 * **strpw - split strings to word
 * @str: input
 * @d: input
 * Return: array of strings, or NULL
 */

char **strpw(char *str, char *d)
{
	int i, j, f, t, numofwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) ||
		!str[i + 1]))
			numofwords++;

	if (numofwords == 0)
		return (NULL);
	s = malloc((1 + numofwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j < numofwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		f = 0;
		while (!is_delim(str[i + f], d) && str[i + f])
			f++;
		s[j] = malloc((f + 1) * sizeof(char));
		if (!s[j])
		{
			for (f = 0; f < j; f++)
				free(s[f]);
			free(s);
			return (NULL);
		}
		for (t = 0; t < f; t++)
			s[j][t] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strpw2 - split strings
 * @str: input
 * @d: input
 * Return: array of strings, or NULL
 */

char **strpw2(char *str, char d)
{
	int i, j, f, t, numofwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	if ((str[i] != d && str[i + 1] == d) ||
	(str[i] != d && !str[i + 1]) || str[i + 1] == d)
	numofwords++;
	if (numofwords == 0)
	return (NULL);
	s = malloc((1 + numofwords) * sizeof(char *));
	if (!s)
	return (NULL);
	for (i = 0, j = 0; j < numofwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		f = 0;
		while (str[i + f] != d && str[i + f] && str[i + f] != d)
			f++;
		s[j] = malloc((f + 1) * sizeof(char));
		if (!s[j])
		{
			for (f = 0; f < j; f++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (t = 0; t < f; t++)
			s[j][t] = str[i++];
		s[j][t] = 0;
	}
	s[j] = NULL;
	return (s);
}

