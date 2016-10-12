###########################################################
# Assignment #: 2
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my second assembly language program.
#                         It does arithmetic. 
###########################################################
#data declarations: declare variable names used in program, storage allocated in RAM
                .data   
num1:           .word 50274 #create a number variable
num2:           .word 0xCB7 #create a number variable in hex
message1:       .asciiz "num1 is: "
message2:       .asciiz "\nnum2 is: "
message3:       .asciiz "\nnum1+num2: "
message4:       .asciiz "\nnum1-num2: "
#program code is contained below under .text
                .text 
                .globl    main    #define a global function main
# the program begins execution at main()
main:
            la $a0, message1  # $a0 = address of message1
            li $v0, 4                # $v0 = 4  --- this is to call print_string()
            syscall                           # call print_string()
            la $t0, num1  # $a0 = address of message1
            lw $a0, 0($t0)  #These bits took me a bit
            li $v0, 1
            syscall
            la $a0, message2
            li $v0, 4
            syscall
            la $t0, num2
            lw $a0, 0($t0)  #I had them adding the addresses, not the numbers in the addresses
            li $v0, 1
            syscall
            la $a0, message3
            li $v0, 4
            syscall
            la $a1, num1
            la $a2, num2
            lw $t2, 0($a1)  #while I'm sure that's very useful for something
            lw $t3, 0($a2)
            add $t0, $t2, $t3
            sub $t1, $t2, $t3
            la $a0, 0($t0)
            li $v0, 1
            syscall
            la $a0, message4
            li $v0, 4
            syscall
            la $a0, 0($t1)      #it was not for this
            li $v0, 1
            syscall
            jr $ra                      # return