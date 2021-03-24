### Makefile ###

all: lab5

lab5: client.o merge_sort.o insertion_sort.o io.c
	gcc -o lab5 client.o merge_sort.o insertion_sort.o io.c

client.o: client.c
	gcc -c client.c

merge_sort.o: merge_sort.c
	gcc -c merge_sort.c

insertion_sort.o: insertion_sort.c
	gcc -c insertion_sort.c

io.o: io.c
	gcc -c io.c
	