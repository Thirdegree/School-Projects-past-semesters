###########################################################
# Assignment #: 6
#  Name: Joel Christiansen 
#  ASU email: jchris27@asu.edu
#  Course: CSE/EEE230, MWF 1:30pm
#  Description: This is my fourth assembly language program.
#                         It uses procedures
###########################################################

                .data
message1:       .asciiz "Specify how many numbers should be stored in the array (at most 9):\n"
message2:       .asciiz "Enter an integer: \n"
message3:       .asciiz "The array has been reversed\n"
message4:       .asciiz "The array content is:\n"
message5:       .asciiz "Please enter an integer to specify how many times to repeat:\n"
message6:       .asciiz "Loop "
newLine:        .asciiz "\n"
array:          .space  36 #array will be stored in $s0


                .text
                .globl main


main:           
                la $s0, array



############################################################################
# Procedure readArray
# Description: Reads an array
# parameters: $a0 = address of array 
# return value: $v0 = length
# registers to be used: $s0 and $s4 will be used.
############################################################################
readArray:
                la $a0, message1
                li $v0, 4
                syscall
                li $v0, 5
                syscall

readLoop:



printArray:

reverseArray:



