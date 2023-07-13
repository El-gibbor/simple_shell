#include <stdio.h>
#include <string.h>

int main(void)
{
	/**
	 * char *strtok(char *str, char *delim)
	 * ------------------------------------
	 * splits a given string from the specified delimiter.
	 * delimiter can be a byte or more bytes/char that delimits the str.
	 * after the first call to this func, a subsequent call to split the next delimited
	 * str takes in NULL as an argument in the str parameter - strtok(NULL, delim)
	 *
	 * Returns ptr to a tokenised null terminated str (fraction of the str splitted by a delimiter) or
  	 * NULL when all chars of the str are all read.
	 */
	char *strToken, *deli = " ", s[] = "this is a string";

	/**
	 * strToken = strtok(s, deli);
	 printf("%s\n", strToken);

	//subsequent call
	strToken = strtok(NULL, deli);
	printf("%s\n", strToken);
	*/

	/*tokenising the entire string*/
	strToken = strtok(s, deli);
	while (strToken)
	{
		printf("%s\n", strToken);
		strToken = strtok(NULL, deli); /*subsequent call*/
	}
	return (0);
}
