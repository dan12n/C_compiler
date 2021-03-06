	.section .mdebug.abi32
	.previous
	.nan    legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.globl ffff
	.set	nomips16
	.set	nomicromips
	.ent	ffff
	.type	ffff, @function
ffff:
	.frame	$fp,44,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -44		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 40($sp)		# frame pointer at stack bottom
	sw	$fp, 36($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations
	move	$2, $0
	li $8, 0	# Decimal:0
	sw $8, 8($fp)

	li $8, 10	# Decimal:10
	sw $8, 8($fp)
	lw $2, 8($fp)	# Moving value from destination register where variable is stored
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	ffff
	.size	ffff, .-ffff
	.align	2

