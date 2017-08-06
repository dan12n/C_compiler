	.section .mdebug.abi32
	.previous
	.nan    legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.globl f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp,28,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -28		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 24($sp)		# frame pointer at stack bottom
	sw	$fp, 20($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations
	move	$2, $0
	sw $a0, 8($fp)
	lw $8, 8($fp)	# Moving value from destination register where variable is stored
	li $9, 10	# Decimal:10
	add $2, $8, $9
	sw $2, 12($fp)
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 24($sp)		# frame pointer at stack bottom
	lw	$fp, 20($sp)		# restore frame pointer
	addiu	$sp, $sp, 28		# Pop off the frame
	j	$31		# Return to caller
	nop
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 24($sp)		# frame pointer at stack bottom
	lw	$fp, 20($sp)		# restore frame pointer
	addiu	$sp, $sp, 28		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.align	2

