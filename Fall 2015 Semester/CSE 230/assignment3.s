###########################################################
# Assignment #: 3
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my third assembly language program.
#                         It does lots of arithmetic. 
###########################################################
#data declarations
            .data
prompt1:    .asciiz "Enter a value:\n"
prompt2:    .asciiz "Enter another value:\n"
prompt3:    .asciiz "Enter one more value:\n"
message1:   .asciiz "num2+num4="
message2:   .asciiz "\nnum2-num3="
message3:   .asciiz "\nnum3*num4="
message4:   .asciiz "\nnum3/num1="
message5:   .asciiz "\nnum2 mod num4="
message6:   .asciiz "\nnum4+(((num1 mod num2-6)/3)*num3)="
            
#main
            .text
            .globl main

main:
        la $a0, prompt1
        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $t0, $v0 #First number

        la $a0, prompt2
        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $t1, $v0 #second number

        la $a0, prompt3
        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $t2, $v0 #third number

        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $t3, $v0 #fouth number

        la $a0, message1
        li $v0, 4
        syscall
        add $t4, $t1, $t3 #second + fourth number
        move $a0, $t4
        li $v0, 1
        syscall

        la $a0, message2
        li $v0, 4
        syscall
        sub $t4, $t1, $t2 #second - third number
        move $a0, $t4
        li $v0, 1
        syscall

        la $a0, message3
        li $v0, 4
        syscall
        mult $t2, $t3 # third * fourth number 
        li $v0, 1
        #mfhi $a0  #get first 32 bits
        #syscall 
        mflo $a0 #get second 32 bits
        syscall

        la $a0, message4
        li $v0, 4
        syscall
        div $t2, $t0
        mflo $a0 #$t2/$t0
        li $v0, 1
        syscall
        la $a0, message5
        li $v0, 4
        syscall
        div $t1, $t3
        li $v0, 1
        mfhi $a0 #$t2 % $t4
        syscall

        la $a0, message6
        li $v0, 4
        syscall
        li $v0, 1
        div $t0, $t1
        mfhi $t4           #num1 % num2
        addi $t5, $t4, -6  #(num1%num2)-6
        li $t4, 3
        div $t5, $t4  
        mflo $t4           #((num1 % num2)-6)/3
        mult $t4, $t2      #(((num1 % num2)-6)/3)*num3
        mflo $t5           #lower 32 of (((num1 % num2)-6)/3)*num3
        add $t6, $t5, $t3  #lower 32 of num4 + (((num1 % num2)-6)/3)*num3
        move $a0, $t6
        syscall

        jr $ra



        


