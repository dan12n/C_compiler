	.file	1 "multiple_function_calls_complex.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	mul
	.set	nomips16
	.set	nomicromips
	.ent	mul
	.type	mul, @function
mul:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	sw	$5,12($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	mul	$2,$3,$2
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	mul
	.size	mul, .-mul
	.align	2
	.globl	add
	.set	nomips16
	.set	nomicromips
	.ent	add
	.type	add, @function
add:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	sw	$5,12($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	add
	.size	add, .-add
	.align	2
	.globl	sub
	.set	nomips16
	.set	nomicromips
	.ent	sub
	.type	sub, @function
sub:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	sw	$4,40($fp)
	sw	$5,44($fp)
	lw	$3,40($fp)
	lw	$2,44($fp)
	subu	$2,$3,$2
	sw	$2,28($fp)
	lw	$5,40($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	add
	nop

	.option	pic2
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	sub
	.size	sub, .-sub
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,56,$31		# vars= 16, regs= 3/0, args= 16, gp= 8
	.mask	0xc0010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	sw	$16,44($sp)
	move	$fp,$sp
	li	$2,5			# 0x5
	sw	$2,28($fp)
	li	$2,11			# 0xb
	sw	$2,32($fp)
	lw	$5,32($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	mul
	nop

	.option	pic2
	move	$16,$2
	lw	$5,32($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	add
	nop

	.option	pic2
	addu	$16,$16,$2
	lw	$5,32($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	sub
	nop

	.option	pic2
	addu	$16,$16,$2
	lw	$5,32($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	add
	nop

	.option	pic2
	sll	$2,$2,1
	subu	$2,$16,$2
	addiu	$2,$2,5
	sw	$2,36($fp)
	lw	$2,36($fp)
	move	$sp,$fp
	lw	$31,52($sp)
	lw	$fp,48($sp)
	lw	$16,44($sp)
	addiu	$sp,$sp,56
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
