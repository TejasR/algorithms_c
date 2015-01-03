CC=gcc

all: selectionSort bubbleSort sequentialSearch firstStringMatch last StringMatch

selectionSort: ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/using_array/selection_sort.h ./Selection\ sort/test_selection_sort_ua.c
	$(CC) -o selectionSort ./Selection\ sort/using_array/selection_sort.c ./Selection\ sort/test_selection_sort_ua.c

bubbleSort: ./bubble_sort/using_array/bubble_sort.c ./bubble_sort/using_array/bubble_sort.h ./bubble_sort/test_bubble_sort_ua.c
	$(CC) -o bubbleSort ./bubble_sort/using_array/bubble_sort.c ./bubble_sort/test_bubble_sort_ua.c

sequentialSearch: ./sequential_search/using_array/sequential_search.c ./sequential_search/using_array/sequential_search.h ./sequential_search/test_sequential_search_ua.c
	$(CC) -o sequentialSearch ./sequential_search/using_array/sequential_search.c ./sequential_search/test_sequential_search_ua.c
    
firstStringMatch: ./brute_force_string_match/first_match/string_match.c ./brute_force_string_match/first_match/string_match.h ./brute_force_string_match/test_first_match.c
	$(CC) -o firstStringMatch ./brute_force_string_match/first_match/string_match.c ./brute_force_string_match/test_first_match.c

lastStringMatch: ./brute_force_string_match/last_match/string_match.c ./brute_force_string_match/last_match/string_match.h ./brute_force_string_match/test_last_match.c
	$(CC) -o lastStringMatch ./brute_force_string_match/last_match/string_match.c ./brute_force_string_match/test_last_match.c

install: selectionSort bubbleSort sequentialSearch firstStringMatch lastStringMatch
	./selectionSort && ./bubbleSort && ./sequentialSearch && ./firstStringMatch && ./lastStringMatch
    
clean: 
	rm selectionSort bubbleSort sequentialSearch firstStringMatch lastStringMatch
