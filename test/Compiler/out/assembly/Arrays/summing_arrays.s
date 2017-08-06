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
	.frame	$fp,180,$31
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp, $sp, -180		# Memory allocation
	#------Saving Preserved registers ----------#
	sw	$31, 176($sp)		# frame pointer at stack bottom
	sw	$fp, 172($sp)		# frame pointer at stack bottom
	move	$fp,$sp		# Copying $sp into $fp. Can use offsets from $fp to access the stack locations
	move	$2, $0
	li $8, 0	# Decimal:0
	sw $8, 8($fp)
	li $8, 10	# Decimal:10
	sw $8, 12($fp)
	li $8, 0	# Decimal:0
	sw $8, 16($fp)
	li $8, 0	# Decimal:0
	sw $8, 20($fp)
	li $8, 0	# Decimal:0
	sw $8, 24($fp)

	sw $8, 28($fp)

	li $8, 0	# Decimal:0
	sw $8, 16($fp)
	li $8, 0	# Decimal:0
	sw $8, 20($fp)
	li $8, 0	# Decimal:0
	sw $8, 24($fp)
	li $8, 0	# Decimal:0
	sw $8, 8($fp)
$top_while_0:	
	lw $9, 8($fp)	# Moving value from destination register where variable is stored
	lw $10, 12($fp)	# Moving value from destination register where variable is stored
	slt $8, $9, $10
	beq $8, $0, $Done_1
	nop
	lw $9, 16($fp)	# Moving value from destination register where variable is stored
	lui	$2,%hi($arr_0_$)
	lw	$2,%lo($arr_0_$)($2)
	move $10, $2
	#-2 global variable: new value -2
	add $9, $9, $10
	sw $9, 32($fp)
	sw $9, 16($fp)
	lui	$2,%hi($arr_0_$)
	lw	$2,%lo($arr_0_$)($2)
	move $10, $2
	#-2 global variable: new value -2
	li $11, 0	# Decimal:0
	slt $9, $11, $10
	beq $9, $0, $bottom_if_2
	nop
	lw $10, 20($fp)	# Moving value from destination register where variable is stored
	lui	$2,%hi($arr_0_$)
	lw	$2,%lo($arr_0_$)($2)
	move $11, $2
	#-2 global variable: new value -2
	add $10, $10, $11
	sw $10, 32($fp)
	sw $10, 20($fp)
	j $bottom_else_3
	nop
$bottom_if_2:	

$bottom_else_3:	
	lui	$2,%hi($arr_0_$)
	lw	$2,%lo($arr_0_$)($2)
	move $10, $2
	#-2 global variable: new value -2
	li $11, 0	# Decimal:0
	slt $9, $10, $11
	beq $9, $0, $bottom_if_4
	nop
	lw $10, 24($fp)	# Moving value from destination register where variable is stored
	lui	$2,%hi($arr_0_$)
	lw	$2,%lo($arr_0_$)($2)
	move $11, $2
	#-2 global variable: new value -2
	add $10, $10, $11
	sw $10, 32($fp)
	sw $10, 24($fp)
	j $bottom_else_5
	nop
$bottom_if_4:	

$bottom_else_5:	
	lw $9, 8($fp)	# Moving value from destination register where variable is stored
	li $10, 1	# Decimal:1
	add $9, $9, $10
	sw $9, 32($fp)
	sw $9, 8($fp)
	j $top_while_0
	nop
$Done_1:	
$Break_L0:
	li $2, 0	# Decimal:0
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 176($sp)		# frame pointer at stack bottom
	lw	$fp, 172($sp)		# restore frame pointer
	addiu	$sp, $sp, 180		# Pop off the frame
	j	$31		# Return to caller
	nop
	move	$sp,$fp		# Copying $fp into $sp
	lw	$31, 176($sp)		# frame pointer at stack bottom
	lw	$fp, 172($sp)		# restore frame pointer
	addiu	$sp, $sp, 180		# Pop off the frame
	j	$31		# Return to caller
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.align	2

