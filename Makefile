CC=gcc

all: selectionSort bubbleSort

selectionSort: ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/using_array/selection_sort.h ./Selection\ sort/test_selection_sort_ua.c
	$(CC) -o selectionSort ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/test_selection_sort_ua.c

bubbleSort: ./bubble_sort/using_array/bubble_sort.c ./bubble_sort/using_array/bubble_sort.h ./bubble_sort/test_bubble_sort_ua.c
	$(CC) -o bubbleSort ./bubble_sort/using_array/bubble_sort.c ./bubble_sort/test_bubble_sort_ua.c

install: selectionSort bubbleSort
	./selectionSort && ./bubbleSort
    
clean: 
	rm selectionSort bubbleSort
