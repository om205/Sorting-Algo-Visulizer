CC = g++
CFLAGS = -Wall -g
OBJS = bubble_sort.o selection_sort.o insersion_sort.o mearge_sort.o quick_sort.o count_sort.o radix_sort.o heap_sort.o

build_and_run: build
	./linux_executable_binary

build: $(OBJS) main.o
	$(CC) -Wall -o linux_executable_binary $^

%.o: %.selection
	$(CC) $(CFLAGS) -c $^

clean: 
	rm *.o *.out *.txt

deep_clean:
	rm *.o *.out *.exe *.txt linux_executable_binary

test: test.cpp heap_sort.cpp
	$(CC) $(CFLAGS) test.cpp heap_sort.cpp
	./a.out