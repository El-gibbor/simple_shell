#include "main.h"

/**
 * words_count - counts the number of words in a string.
 * @s: a pointer to the string whose words are to be counted.
 * @delim: a pointer to the delimiter.
 * Return: the number of words counted.
 */
size_t words_count(const char *s, const char *delim)
{
	bool_t delim_found = TRUE;
	size_t num_words = 0;
	size_t i;

	while (*s != '\0')
	{
		/* Loop through s2 to find match */
		for (i = 0; delim[i] && *s != delim[i]; i++)
			;
		if (*s == delim[i])
			delim_found = TRUE;
		else
		{
			if (delim_found)
				num_words++;
			delim_found = FALSE;
		}
		s++;
	}
	return (num_words);
}

/**
 * tokenize_str - tokenizes a string into an array of strings.
 * @str: a pointer to the string to be tokenized.
 * @delim: a pointer to the delimiter.
 * Return: a pointer to the array of strings created.
 */
char **tokenize_str(char *str, char *delim)
{
	char **tokens_array = NULL;
	size_t numOfWords, word_len;
	size_t i;

	if (!str || !delim)
		return (NULL);
	numOfWords = words_count(str, delim);

	tokens_array = malloc(sizeof(char *) * (numOfWords + 1));
	if (tokens_array == NULL)
		return (NULL);

	for (i = 0; i < numOfWords; i++)
	{
		str += _strspn(str, delim);
		word_len = strpbrk_no(str, delim);

		tokens_array[i] = malloc(sizeof(char) * (word_len + 1));
		if (tokens_array[i] == NULL)
		{
			while (i--)
				free(tokens_array[i]);
			free(tokens_array);
			return (NULL);
		}
		_strncpy(tokens_array[i], str, word_len);
		str += word_len;
	}
	tokens_array[i] = NULL;
	return (tokens_array);
}
