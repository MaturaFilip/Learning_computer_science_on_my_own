
stack_test:	stack_rpn.o	stackADT_dynamic.o
		gcc -o stack_test stack_rpn.o stackADT_dynamic.o

stack_rpn.o:	stack_rpn.c	stackADT2.h
		gcc -c stack_rpn.c

stackADT_dynamic.o:	stackADT_dynamic.c	stackADT2.h
		gcc -c stackADT_dynamic.c

