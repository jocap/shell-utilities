out/%: %.c
	cc -Wall -Wno-missing-braces -Wextra -pedantic -O2 $< -o $@

symlinks:
	ln -sf $$(find $$PWD -type file ! -name Makefile ! -name '*.c' ! -path '*/.*') ~/bin
