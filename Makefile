CC=gcc

all: selectionSort bubbleSort sequentialSearch firstStringMatch lastStringMatch

selectionSort: ./brute_force/selection_sort/using_array/selection_sort.c ./brute_force/selection_sort/using_array/selection_sort.h ./brute_force/selection_sort/test_selection_sort_ua.c
	$(CC) -o selectionSort ./brute_force/selection_sort/using_array/selection_sort.c ./brute_force/selection_sort/test_selection_sort_ua.c

bubbleSort: ./brute_force/bubble_sort/using_array/bubble_sort.c ./brute_force/bubble_sort/using_array/bubble_sort.h ./brute_force/bubble_sort/test_bubble_sort_ua.c
	$(CC) -o bubbleSort ./brute_force/bubble_sort/using_array/bubble_sort.c ./brute_force/bubble_sort/test_bubble_sort_ua.c

sequentialSearch: ./brute_force/sequential_search/using_array/sequential_search.c ./brute_force/sequential_search/using_array/sequential_search.h ./brute_force/sequential_search/test_sequential_search_ua.c
	$(CC) -o sequentialSearch ./brute_force/sequential_search/using_array/sequential_search.c ./brute_force/sequential_search/test_sequential_search_ua.c
    
firstStringMatch: ./brute_force/string_match/first_match/string_match.c ./brute_force/string_match/first_match/string_match.h ./brute_force/string_match/test_first_match.c
	$(CC) -o firstStringMatch ./brute_force/string_match/first_match/string_match.c ./brute_force/string_match/test_first_match.c

lastStringMatch: ./brute_force/string_match/last_match/string_match.c ./brute_force/string_match/last_match/string_match.h ./brute_force/string_match/test_last_match.c
	$(CC) -o lastStringMatch ./brute_force/string_match/last_match/string_match.c ./brute_force/string_match/test_last_match.c

install: selectionSort bubbleSort sequentialSearch firstStringMatch lastStringMatch
	./selectionSort && ./bubbleSort && ./sequentialSearch && ./firstStringMatch && ./lastStringMatch
    
clean: 
	rm selectionSort bubbleSort sequentialSearch firstStringMatch lastStringMatch
