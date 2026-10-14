mypreprocessor : main.o comment_removal.o header_inclusion.o macro_replacement.o
	gcc main.o comment_removal.o header_inclusion.o macro_replacement.o -o mypreprocessor

main.o : main.c
	gcc -c main.c

comment_removal.o : comment_removal.c
	gcc -c comment_removal.c

header_inclusion.o : header_inclusion.c
	gcc -c header_inclusion.c

macro_replacement.o : macro_replacement.c
	gcc -c macro_replacement.c

clean:
	rm -f *.o mypreprocessor a.out

