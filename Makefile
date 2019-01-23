%: %.c
	gcc -Wall -Wno-missing-braces -Wextra -Wpedantic $@.c -o out/$@
