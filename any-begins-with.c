#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <err.h>

/* any-begins-with.c
 * -- returns any line on stdin that begins with argv[1]
 */

int main(int argc, char *argv[]) {
	bool success = false;

	if (argc < 2) {
		fprintf(stderr, "usage: ... | %s string\n", argv[0]);
		return 1;
	}

	char *line = NULL;
	size_t size = 0;

	while (getline(&line, &size, stdin) != -1) {
		if (strncmp(argv[1], line, strlen(argv[1])) == 0) {
			success = true;
			printf("%s", line);
		}
	}

	free(line);
	if (ferror(stdin))
		err(1, "getline");

	if (success)
		return 0;
	else
		return 1;
}
