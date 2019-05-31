../bin/scan: scan.c
	cc -Wall -Wno-missing-braces -Wextra -Wno-format-security -pedantic -O2 $< -o $@

../bin/%: %.c
	cc -Wall -Wno-missing-braces -Wextra -pedantic -O2 $< -o $@
