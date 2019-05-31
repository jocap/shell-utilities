symlinks:
	IFS=$$'\n' ln -sf $$(find $$PWD -type file ! -name Makefile ! -name GNUmakefile ! -name '*.c' ! -path '*/.*') ~/bin
