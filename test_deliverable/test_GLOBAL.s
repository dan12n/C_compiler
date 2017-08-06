	.section .mdebug.abi32
	.previous
	.nan    legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.globl	z
	.data
	.align	2
	.type	z, @object
z:
	.word	0
	.text	
	.align	2

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
	lui	$2,%hi(z)
	lw	$2,%lo(z)($2)
	move $9, $2
	#-2 global variable: new value -2
	li $10, 2	# Decimal:2
	mul $8, $9, $10
	sw $8, 12($fp)

	lw $8, 12($fp)	# Moving value from destination register where variable is stored
	li $9, 20	# Decimal:20
	add $2, $8, $9
	sw $2, 16($fp)
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

