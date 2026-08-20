
stack_test:	stackclient.o	stackADT_dynamic.o
		gcc -o stack_test stackclient.o stackADT_dynamic.o

stackclient.o:	stackclient.c	stackADT2.h
		gcc -c stackclient.c

stackADT_dynamic.o:	stackADT_dynamic.c	stackADT2.h
		gcc -c stackADT_dynamic.c

