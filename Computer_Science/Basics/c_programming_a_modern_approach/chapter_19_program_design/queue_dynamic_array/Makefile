
queue_test:	clientqueue.o	queue_array.o
		gcc -o queue_test clientqueue.o queue_array.o

clientqueue.o:	clientqueue.c	queue.h
		gcc -c clientqueue.c

queue_array.o:	queue_array.c	queue.h
		gcc -c queue_array.c

