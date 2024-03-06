main: main.o LinkedList.o
   gcc main.o LinkedList.o -o main

main.o: main.c
   gcc   -c main.c

LinkedList.o: LinkedList.c LinkedList.h
   gcc   -c LinkedList.c

clean:
   rm *.o
