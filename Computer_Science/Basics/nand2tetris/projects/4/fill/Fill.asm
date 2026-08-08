// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.


@SCREEN
D=A
@addr
M=D     // addr = 16_384 screen's base address


(WHITE_LOOP)
    @addr
    A=M
    M=0    // RAM[addr] = 0

    @1
    D=A
    @addr
    M=D+M   // addr = addr + 1
    @KBD
    D=M
    @RESET_BLACK
    D;JNE
    @WHITE_LOOP
    0;JMP


(BLACK_LOOP)
    @addr
    A=M
    M=-1    // RAM[addr] = -1 aka 1111111111111111 (BLACK)

    @1
    D=A
    @addr
    M=D+M   // addr = addr + 1
    
    @KBD
    D=M
    @BLACK_LOOP
    D;JNE
    @RESET_WHITE
    0;JMP

(RESET_BLACK)
    @SCREEN
    D=A
    @addr
    M=D
    @BLACK_LOOP
    0;JMP

(RESET_WHITE)
    @SCREEN
    D=A
    @addr
    M=D 
    @WHITE_LOOP
    0;JMP

