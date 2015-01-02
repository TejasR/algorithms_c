CC=gcc

all: selection_sort

selection_sort: ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/using_array/selection_sort.h ./Selection\ sort/test_selection_sort_ua.c
	$(CC) -o selection_sort ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/test_selection_sort_ua.c

install: selection_sort
	./selection_sort