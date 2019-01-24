out/%: %.c
	cc -Wall -Wno-missing-braces -Wextra -pedantic $< -o $@
