
stack_test:	stack_valid_parentheses.o	stackADT_dynamic.o
		gcc -o stack_test stack_valid_parentheses.o stackADT_dynamic.o

stack_valid_parentheses.o:	stack_valid_parentheses.c	stackADT2.h
		gcc -c stack_valid_parentheses.c

stackADT_dynamic.o:	stackADT_dynamic.c	stackADT2.h
		gcc -c stackADT_dynamic.c

