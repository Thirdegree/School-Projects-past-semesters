###########################################################
# Assignment #: 4
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my fourth assembly language program.
#                         It does Home payment assignment
###########################################################
                    .data
message1:           .asciiz "Please enter a number of months to rent an apartment:\n"
message2:           .asciiz "Would you like to rent an apartment of one bedroom or two bedrooms?\n"
message3:           .asciiz "Sorry, we have only one or two bedroom apartments.\n"
message4:           .asciiz "Your total rent: "
message5:           .asciiz " dollars for "
message6:           .asciiz " months\n"


                    .text
                    .globl main

main:
        la $a0, message1    #get number of months
        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $s0, $v0       #number of months

        la $a0, message2    #get number of rooms
        li $v0, 4   
        syscall
        li $v0, 5
        syscall
        move $s1, $v0       #number of rooms

        
                            #if statements   
        li $t0, 1           #"Sorry" aka case1
        slt $t3, $s1, $t0   
        bne $t3, $zero, case1
        li $t0, 2
        sgt $t3, $s1, $t0
        bne $t3, $zero, case1

        li $t0, 1           #case2
        seq $t3, $t0, $s1   #numberofrooms == 1
        sgt $t4, $s0, $zero #months > 0
        li $t0, 6
        slt $t5, $s0, $t0   #months < 6
        sne $t3, $zero, $t3 #(numberofrooms == 1) == true
        seq $t0, $t3, $t4   #numberofrooms == 1 && months > 0
        seq $t0, $t5, $t0   #numberofrooms == 1 && months > 0 && months <6
        bne $t0, $zero, case2

        li $t0, 1           #case3
        seq $t3, $t0, $s1   #numberofrooms == 1
        li $t0, 6
        sge $t4, $s0, $t0   #months >= 6
        sne $t3, $zero, $t3 #(numberofrooms == 1) == true
        seq $t3, $t4, $t3   #numberofrooms == 1 && months >= 0
        bne $t3, $zero, case3

        li $t0, 2           #case4
        seq $t3, $t0, $s1   #numberofrooms == 2
        sgt $t4, $s0, $zero #months > 0
        li $t0, 6
        slt $t5, $s0, $t0   #months < 6
        sne $t3, $zero, $t3 #(numberofrooms == 2) == true
        seq $t0, $t3, $t4   #numberofrooms == 2 && months > 0
        seq $t0, $t5, $t0   #numberofrooms == 2 && months > 0 && months <6
        bne $t0, $zero, case4

        li $t0, 2           #case5
        seq $t3, $t0, $s1   #numberofrooms == 2
        li $t0, 6
        sge $t4, $s0, $t0   #months >= 6
        sne $t3, $zero, $t3 #(numberofrooms == 2) == true
        seq $t3, $t4, $t3   #numberofrooms == 2 && months >= 0
        bne $t3, $zero, case5

        li $s2, 0
        j exit2

case1:
        li $v0, 4
        la $a0, message3
        syscall
        j exit1

case2:
        li $s2, 600
        mult $s2, $s0
        mflo $s2 
        j exit2

case3:
        li $s2, 600
        mult $s2, $s0
        mflo $s2 
        addi $s2, $s2, -200
        j exit2

case4:
        li $s2, 900
        mult $s2, $s0
        mflo $s2 
        j exit2

case5:
        li $s2, 900
        mult $s2, $s0
        mflo $s2 
        addi $s2, $s2, -300
        j exit2

exit1:
        jr $ra

exit2:
        li $v0, 4
        la $a0, message4
        syscall
        li $v0, 1
        move $a0, $s2
        syscall
        li $v0, 4
        la $a0, message5
        syscall
        li $v0, 1
        move $a0, $s0
        syscall
        li $v0, 4
        la $a0, message6
        syscall
        jr $ra