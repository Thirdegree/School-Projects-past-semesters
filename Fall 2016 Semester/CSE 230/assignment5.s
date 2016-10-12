###########################################################
# Assignment #: 5
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my fourth assembly language program.
#                         It does more math
###########################################################

                .data
numbers_len:    .word   14 
numbers:        .word   11, 24, 3, -6, 14, -18, 21, 45, 12, -27, 35, -7, 44, -28
message1:       .asciiz "Enter an integer:\n"
message2:       .asciiz "Enter another integer:\n"
message3:       .asciiz "The sum of numbers that are inbetween:"
newline:        .asciiz "\n"
test:           .asciiz "test"

                .text
                .globl main

main:
        li      $v0, 4
        la      $a0, message1
        syscall
        li      $v0, 5
        syscall
        move    $s0, $v0        #First integer

        li      $v0, 4
        la      $a0, message2
        syscall
        li      $v0, 5
        syscall
        move    $s1, $v0        #second integer

        slt     $t0, $s0, $s1   #$t0 = 1 if $s0<$s1
        li      $t8, 0          #i
        li      $s2, 0          #accum   
        bne     $t0, $zero, Reassign


Loop:   
         
        la      $t1, numbers    #base address
        sll     $t2, $t8, 2     #offset
        add     $t5, $t2, $t1   #address + offset
        lw      $t4, 0($t5)     #now holds the value
        bgt     $s1, $t4, Loop2
        blt     $s0, $t4, Loop2


Add:
        add     $s2, $s2, $t4   #accumulating     

Loop2:
        li      $t3, 56         #length of array in bytes
        ble     $t3, $t2, Exit  #leave the loop
        addi    $t8, $t8, 1
        j       Loop



Reassign:   
        move    $t1, $s0
        move    $s0, $s1        #now smallest numbers
        move    $s1, $t1        #now largest number
        j       Loop

Exit:   
        li      $v0, 4
        la      $a0, message3
        syscall
        li      $v0, 1
        move    $a0, $s2        #accum
        syscall
        jr $ra
