#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t _getline(char **line, size_t *buff, int fd)
{
	char lineBuf[1024];
	ssize_t num_read;

	num_read = read(fd, lineBuf, 1024);
	if (num_read == -1)
		return (-1);

	*line = malloc(num_read + 1);
	if (!*line)
		return (-1);

	/* make the buffer a str (null terminated),
	   so that it can be copied into
	   */
	lineBuf[num_read] = '\0';
	strcpy(*line, lineBuf);
	*buff = num_read + 1;

	return (num_read);
}

int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	char readBuff[15];

	printf("$ ");
	fflush(stdout); /*flush output buffer and diplay prompt*/
	ssize_t line_num = _getline(&buff, &n, STDIN_FILENO);
	printf("%sbuffer size: %d\n", buff, (int)line_num);

	free(buff);
	return (0);
}
