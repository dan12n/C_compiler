	.section .mdebug.abi32
	.previous
	.nan    legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.globl main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,60,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro

	addiu	$sp, $sp, -60		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 56($sp)		# frame pointer at stack bottom
	sw	$fp, 52($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations

	la $s0, size # initialize registers
	lw $s1, 0($s0) # $s1 = size
	ori $s2, $0, 0 # $s2 = sum
	ori $s3, $0, 0 # $s3 = pos
	ori $s4, $0, 0 # $s4 = neg
# <init>
	ori $s5, $0, 0 # $s5 = i
	la $s6, arr # $s6 = &arr
# if (<cond>)
L1: bge $s5, $s1, DONE
# <for-body>
	lw $s7, 0($s6) # $s7 = arr[i]
	addu $s2, $s2, $s7 # sum += arr[i]
	blez $s7, NEG # if ! (arr[i] > 0)
	addu $s3, $s3, $s7 # pos += arr[i];
	j UPDATE # goto UPDATE
NEG: bgez $s7, UPDATE # if ! (arr[i] < 0)
	addu $s4, $s4, $s7 # neg += arr[i];

UPDATE: # <update>
	addi $s5, $s5, 1 # i++
	addi $s6, $s6, 4 # move array pointer
	j L1 # goto L1
DONE:

	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 56($sp)		# frame pointer at stack bottom
	lw	$fp, 52($sp)		# restore frame pointer
	addiu	$sp, $sp, 60		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.align	2

	.data
	size: .word 10
	arr: .word 12, -1, 8, 0, 6, 85, -74, 23, 99, -30