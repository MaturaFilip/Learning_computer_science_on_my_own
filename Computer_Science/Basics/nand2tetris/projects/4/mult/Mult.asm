// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.

// RAM[0] = some number, RAM[1] = some number
// RAM[2] = RAM[0] * RAM[1]
// assumptions: RAM[0] and RAM[0] > 0 and < 32_768

/*
int main()
{
   int ram_1 = 2;
   int ram_2 = 3;
   int n = ram_1;
   int i = 0;
   int sum = 0;
   for (; i < n; i++) {
       sum += ram_2;
   }
   printf("%d\n", sum);

    return 0;
}
*/

// initialize variables
@R0
D=M
@n
M=D // n = R0

@sum
M=0

@i
M=0

(LOOP)
    // for (i = 0; i < n; i++
    @i
    D=M
    @n
    D=D-M
    @STOP
    D;JEQ

    @R1
    D=M
    @sum
    D=D+M
    M=D

    @i
    M=M+1
    @LOOP
    0;JMP


(STOP)
    @sum
    D=M
    @R2
    M=D

(END)
    @END
    0;JMP



