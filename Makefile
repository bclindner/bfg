default: clean
	gcc -std=c99 -pedantic -o bfg bfg.c
clean:
	-rm gcc
