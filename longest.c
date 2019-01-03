#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <err.h>

/* longest.c
 * -- prints the longest line in stdin, or if the two longest lines
 * -- are of equal length, the first one
 */

int main(int argc, char *argv[]) {
	if (argc > 1) {
		fprintf(stderr, "usage: ... | %s\n", argv[0]);
		return 1;
	}

	char *line = NULL;
	int length = 0;
	size_t size = 0;

	char *longest = NULL;
	int longest_length = 0;

	while (getline(&line, &size, stdin) != -1) {
		length = strlen(line);
		if (length > longest_length) {
			longest_length = length;
			longest = strdup(line);
			if (longest == NULL)
				err(1, "strdup");
		}
	}

	free(line);
	if (ferror(stdin))
		err(1, "getline");

	printf("%s", longest);
	return 0;
}
