
bminor: compiler_test.o 
	gcc compiler_test.o

%.o: %.c *.h
	gcc -Wall -c $< -o $@ -g


clean:
	rm -f parser.* parser.output scanner.c *.o bminor
