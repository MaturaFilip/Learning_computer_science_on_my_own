
queue_test:	clientqueue.o	queue_linked_list.o
		gcc -o queue_test clientqueue.o queue_linked_list.o

clientqueue.o:	clientqueue.c	queue.h
		gcc -c clientqueue.c

queue_linked_list.o:	queue_linked_list.c	queue.h
		gcc -c queue_linked_list.c

