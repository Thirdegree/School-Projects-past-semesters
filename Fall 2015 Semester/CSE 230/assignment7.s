###########################################################
# Assignment #: 7
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my seven assembly language program.
#                         It uses the stack
###########################################################

            .data
message1:   .asciiz "Enter an integer:\n"
message2:   .asciiz "The solution is: "
new_line:   .asciiz "\n"

            .text
            .globl main

main:
            la      $a0, message1
            li      $v0, 4
            syscall
            li      $v0, 5
            syscall
            move    $a0, $v0
            addi    $sp, $sp, -4
            sw      $ra, 0($sp)
            jal     function1
            lw      $ra, 0($sp)
            addi    $sp, $sp, 4
            la      $a0, message2
            move    $s0, $v0
            li      $v0, 4
            syscall
            li      $v0, 1
            move    $a0, $s0
            syscall
            li      $v0, 4
            la      $a0, new_line
            syscall
            jr      $ra

############################################################################
# Procedure function1
# Description: Does the thing
# parameters: $a0 = n
# return value: $v0 = n-5 or 4*function1(n-1) - n*function1(n-3)
# registers to be used: $s0, $s1, $s2, $s3, $t0, $t1
############################################################################
function1:
            #if n<=3
            li      $s2, 3
            ble     $a0, $s2, returnValue

            #else
            addi    $sp, $sp, -8
            sw      $a0, 4($sp)
            sw      $ra, 0($sp)

            addi    $t0, $a0, -1
            addi    $t1, $a0, -3

            #n*function1(n-3)
            move    $a0, $t1
            jal     function1
            lw      $a0, 4($sp) #get n back
            lw      $ra, 0($sp)
            mult    $v0, $a0
            mflo    $s0         


            #4*function1(n-1)
            move    $a0, $t0
            jal     function1
            lw      $a0, 4($sp) #get n back
            lw      $ra, 0($sp)
            addi    $sp, $sp, 8
            li      $s1, 4
            mult    $v0, $s1
            mflo    $s1


           

            #sub 
            sub     $v0, $s1, $s0 #return this
            jr      $ra







############################################################################
# Procedure returnValue
# Description: gives n-5
# parameters: $a0 = n
# return value: $v0 = n-5 
# registers to be used: 
############################################################################
returnValue:
            addi $v0, $a0, -5
            jr $ra