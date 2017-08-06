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
	.frame	$fp,52,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -52		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 48($sp)		# frame pointer at stack bottom
	sw	$fp, 44($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations
	move	$2, $0
	li $8, 0	# Decimal:0
	sw $8, 8($fp)

$top_while_0:	
	lw $9, 8($fp)	# Moving value from destination register where variable is stored
	li $10, 5	# Decimal:5
	slt $8, $9, $10
	beq $8, $0, $Done_1
	nop
	lw $9, 8($fp)	# Moving value from destination register where variable is stored
	li $10, 1	# Decimal:1
	add $9, $9, $10
	sw $9, 12($fp)
	sw $9, 8($fp)
	j $top_while_0
	nop
$Done_1:	
$Break_L0:
	lw $2, 8($fp)	# Moving value from destination register where variable is stored
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 48($sp)		# frame pointer at stack bottom
	lw	$fp, 44($sp)		# restore frame pointer
	addiu	$sp, $sp, 52		# Pop off the frame
	j	$31		# Return to caller
	nop
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 48($sp)		# frame pointer at stack bottom
	lw	$fp, 44($sp)		# restore frame pointer
	addiu	$sp, $sp, 52		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.align	2

