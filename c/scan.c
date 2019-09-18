#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

/* note to user: beware of format string exploit */

int main(int argc, char *argv[]) {
	int i, max, size;
	char *fmt, *r[10], chr;

	if (argc != 3 && argc != 4) {
		fprintf(stderr, "usage: %s format n [strsize]\n", argv[0]);
		return 1;
	}

	max = atoi(argv[2]); // please pass numbers
	if (argc == 4) size = atoi(argv[3]);
	else size = 255;

	for (i = 0; i < max; i++)
		if ((r[i] = malloc(size * sizeof (char))) == NULL)
			err(1, "malloc");

	if ((fmt = malloc((strlen(argv[1]) + 2 + 1) * sizeof (char))) == NULL)
		err(1, "malloc");

	sprintf(fmt, "%s%%c", argv[1]);
	printf("%s\n", fmt);
	return 0;

#define scan(...) do { if (scanf(fmt, __VA_ARGS__, &chr) != max) exit(1); } while (0)

	if (max == 1) scan(r[0]);
	if (max == 2) scan(r[0], r[1]);
	if (max == 3) scan(r[0], r[1], r[2]);
	if (max == 4) scan(r[0], r[1], r[2], r[3]);
	if (max == 5) scan(r[0], r[1], r[2], r[3], r[4]);
	if (max == 6) scan(r[0], r[1], r[2], r[3], r[4], r[5]);
	if (max == 7) scan(r[0], r[1], r[2], r[3], r[4], r[5], r[6]);
	if (max == 8) scan(r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7]);
	if (max == 9) scan(r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8]);
	if (max == 10) scan(r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9]);

	for (i = 0; i < max; i++) {
		printf("%s", r[i]);
		putchar('\0');
	}
}
