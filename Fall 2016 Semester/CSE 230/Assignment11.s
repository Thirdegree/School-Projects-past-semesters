###########################################################
# Assignment #: 11
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: floating point stuff 
###########################################################
#data declarations: declare variable names used in program, storage allocated in RAM
                .data   
message1:       .asciiz "Enter a number:\n"
message2:       .asciiz "The array contains the following:\n"
newLine:        .asciiz "\n"
array1:         .align 5
                .space 320   
#program code is contained below under .text
                .text 
                .globl    main    #define a global function main
# the program begins execution at main()
main:
    li $t0, 0               #int i = 0;
    li $t1, 10              #int arraysize = 10;
    la $a1, array1          #int array[10] 
    addi $sp, $sp, -4       #creating a loop
    sw $ra, 0($sp)
    jal loop1
    lw $ra, 0($sp)
    addi $sp, $sp, 4        #end of loop
    li $v0, 4
    la $a0, message2
    syscall
    li $t0, 0               #int i=0;
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal loop3
    lw $ra, 0($sp)
    addi $sp, $sp, 4        #end of loop
    jr $ra


loop1: 
    slt $t2, $t0, $t1       #i<10
    li $a2, 0               #needs to branch if i is NOT less than
    beq $t2, $a2, loopExit
    li $v0, 4
    la $a0, message1
    li $t3, 0               #int alreadyStored = 0;
    syscall
    li $v0, 6
    syscall                 #scanf("%f", &num); //Stored in $f0,$f1
    li $t4, 0               #int j=0;
    li.s $f8, 1.0
    li.s $f6, 0.0
    c.eq.s $f8, $f6         #setting the eq to false
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    jal loop2
    lw $ra, 0($sp)
    addi $sp, $sp, 4        #end of loop2
    bc1t loop1
    sll $t5, $t0, 5
    add $t5, $t5, $a1       #address for array[i]
    s.s $f0, 0($t5)         #array[i]=num
    addi $t0, $t0, 1        #i++
    j loop1                 #end of loop

loop2:
    slt $t2, $t4, $t0       #j<i
    beq $t2, $a2, loopExit  #branches if j>=i
    sll $t5, $t4, 5         #5 because it's an array of floats not ints
    add $t5, $t5, $a1       #finding the address in the array for array[j]
    l.s $f2, 0($t5)         #gets array[j]
    c.eq.s $f0, $f2         #array[j]==num
    addi $t4, $t4, 1
    bc1f loop2
    jr $ra

loop3:
    slti $t2, $t0, 10
    beq $t2, 0, loopExit
    sll $t5, $t0, 5
    add $t5, $t5, $a1
    li $v0, 2
    l.s $f12, 0($t5)
    syscall
    la $a0, newLine
    li $v0, 4
    syscall
    addi $t0, $t0, 1
    j loop3

loopExit:
    jr $ra