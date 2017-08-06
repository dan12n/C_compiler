	.section .mdebug.abi32
	.previous
	.nan    legacy
	.module fp=xx
	.module nooddspreg
	.abicalls
	.globl factorial
	.set	nomips16
	.set	nomicromips
	.ent	factorial
	.type	factorial, @function
factorial:
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
	sw $a0, 8($fp)
	lw $9, 8($fp)	# Moving value from destination register where variable is stored
	li $10, 5	# Decimal:5
	slt $8, $9, $10
	beq $8, $0, $bottom_if_0
	nop
	li $2, 1	# Decimal:1
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop
	j $bottom_else_1
	nop
$bottom_if_0:	
	sw $a0, 12($fp)
	lw $11, 8($fp)	# Moving value from destination register where variable is stored
	li $12, 1	# Decimal:1
	sub $10, $11, $12
	move $a0, $10
	.option pic0 
	jal factorial
	nop
	.option pic2 
	lw $11, 8($fp)
	lw $9, 8($fp)
	move $9, $2
	sw $9, 28($fp)
	lw $a0, 12($fp)
	li $11, 1	# Decimal:1
	add $2, $9, $11
	sw $2, 12($fp)
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop
$bottom_else_1:	
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	factorial
	.size	factorial, .-factorial
	.align	2

