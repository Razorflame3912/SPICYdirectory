all: dir.c
	gcc dir.c

clean:
	rm -f a.out

run: all
	./a.out
