#include <stdio.h>
#include <stdlib.h>
#include <err.h>

/* append-to.c
 * -- appends each line from stdin to each argument
 */

int main(int argc, char *argv[]) {

	if (argc < 2) {
		fprintf(stderr, "usage: %s words ...\n", argv[0]);
		return 1;
	}

	char *line = NULL;
	size_t size;
	size_t i = 1;

	while (getline(&line, &size, stdin) != -1) {
		if (i >= argc) {
			fprintf(stderr, "error: more lines than words\n");
			return 1;
		}
		printf("%s %s", argv[i], line);
		i++;
	}

	free(line);
	if (ferror(stdin))
		err(1, "getline");

	/* print rest of words if necessary */
	while (i < argc) {
		printf("%s\n", argv[i]);
		i++;
	}

	return 0;
}
