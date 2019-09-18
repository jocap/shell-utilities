#include <stdio.h>
#include <unistd.h>

int main()
{
	int c;

	if (read(STDIN_FILENO, &c, 1) <= 0 || c == 0) return 1;
	else putchar(c);

	while (read(STDIN_FILENO, &c, 1) > 0 && c != 0) {
		putchar(c);
	}
}
