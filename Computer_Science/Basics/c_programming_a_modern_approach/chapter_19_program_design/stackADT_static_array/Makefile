
stack_test:	stackclient.o	stackADT_fixed_array.o
		gcc -o stack_test stackclient.o stackADT_fixed_array.o

stackclient.o:	stackclient.c	stackADT.h
		gcc -c stackclient.c

stackADT_fixed_array.o:	stackADT_fixed_array.c	stackADT.h
		gcc -c stackADT_fixed_array.c

