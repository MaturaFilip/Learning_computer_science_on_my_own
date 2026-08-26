
stack_test:	stackclient.o	stackADT_linked_list.o
		gcc -o stack_test stackclient.o stackADT_linked_list.o

stackclient.o:	stackclient.c	stackADT2.h
		gcc -c stackclient.c

stackADT_linked_list.o:	stackADT_linked_list.c	stackADT2.h
		gcc -c stackADT_linked_list.c

