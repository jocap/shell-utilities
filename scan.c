#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

/* note to user: beware of format string exploit */

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s format\n", argv[0]);
		return 1;
	}

	int n;

	char *line = NULL;
	size_t size;
	ssize_t len;

	while((len = getline(&line, &size, stdin)) != -1) {
		line[strlen(line) - 1] = '\0'; /* remove newline */
		char x[size];
		n = sscanf(line, argv[1], x);
		if (n == 1) printf("%s\n", x);
		if (n == EOF) {
			fprintf(stderr, "input failure\n");
			return 1;
		}
	}

	free(line);
	if (ferror(stdin))
		err(1, "getline");

	if (n == 1)
		return 0;
	else
		return 1;
}
