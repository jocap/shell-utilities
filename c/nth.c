#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <err.h>

int main(int argc, char *argv[]) {
	int start, end;
	bool no_end;

	no_end = false; /* signified by argv[2] being "-" */

	if (argc == 2) {
		start = atoi(argv[1]); /* it's up to you to provide correct input */
		end = start;
	} else if (argc == 3) {
		start = atoi(argv[1]);
		if (strcmp(argv[2], "-") == 0) {
			no_end = true;
			end = start; /* so that input checks don't fail later */
		} else end = atoi(argv[2]);
	} else {
		fprintf(stderr, "usage: %s n [m]\n(echo line n [through m])\n(if m is -, then no limit is set)\n", argv[0]);
		exit(1);
	}

	if (start < 0 || end < 0) {
		fprintf(stderr, "numbers can't be negative\n");
		exit(1);
	}

	if (start > end) {
		fprintf(stderr, "first number is larger than second\n");
		exit(1);
	}

	char *line = NULL;
	size_t size;
	ssize_t len;
	ssize_t i = 1;

	while((len = getline(&line, &size, stdin)) != -1) {
		if (i >= start ) fwrite(line, len, 1, stdout);
		if (! no_end && i >= end) goto exit;
		i++;
	}

exit:
	free(line);
	if (ferror(stdin))
		err(1, "getline");

	return 0;
}
