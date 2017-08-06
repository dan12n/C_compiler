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
	li $9, 30	# Decimal:30
	li $10, 10	# Decimal:10
	slt $8, $9, $10
	beq $8, $0, $bottom_if_0
	nop
	li $2, 30	# Decimal:30
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop
	j $bottom_else_1
	nop
$bottom_if_0:	
	li $2, 10	# Decimal:10
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 40($sp)		# frame pointer at stack bottom
	lw	$fp, 36($sp)		# restore frame pointer
	addiu	$sp, $sp, 44		# Pop off the frame
	j	$31		# Return to caller
	nop
$bottom_else_1:	
	li $2, 5	# Decimal:5
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
	.end	f
	.size	f, .-f
	.align	2

