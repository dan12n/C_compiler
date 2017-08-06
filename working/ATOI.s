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
	.frame	$fp,36,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -36		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 32($sp)		# frame pointer at stack bottom
	sw	$fp, 28($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations
	move	$2, $0
	sw $8, 8($fp)

	sw $a0, 12($fp)
	lw $8, 8($fp)	# Moving value from destination register where variable is stored
	move $a0, $8
	.option pic0 
	jal atoi
	nop
	.option pic2 
	lw $8, 8($fp)
	move $2, $2
	sw $2, 28($fp)
	lw $a0, 12($fp)
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 32($sp)		# frame pointer at stack bottom
	lw	$fp, 28($sp)		# restore frame pointer
	addiu	$sp, $sp, 36		# Pop off the frame
	j	$31		# Return to caller
	nop
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 32($sp)		# frame pointer at stack bottom
	lw	$fp, 28($sp)		# restore frame pointer
	addiu	$sp, $sp, 36		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.align	2

