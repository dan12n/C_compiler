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
	move	$2, $0
	li $8, 7	# Decimal:7
	sw $8, 8($fp)

	sw $8, 12($fp)

	lui	$2,%hi($x_2_$)
	lw	$2,%lo($x_2_$)($2)
	lw $8, 8($fp)	# Moving value from destination register where variable is stored
	#Could not find declaration, assuming global variable
	lui $2,%hi($x_2_$)
	sw  $8,%lo($x_2_$)($2)
	lui	$2,%hi($x_3_$)
	lw	$2,%lo($x_3_$)($2)
	move $2, $2
	#-2 global variable: new value -2
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 56($sp)		# frame pointer at stack bottom
	lw	$fp, 52($sp)		# restore frame pointer
	addiu	$sp, $sp, 60		# Pop off the frame
	j	$31		# Return to caller
	nop
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

