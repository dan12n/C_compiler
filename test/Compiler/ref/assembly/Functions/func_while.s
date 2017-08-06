	.file	1 "func_while.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	pop
	.set	nomips16
	.set	nomicromips
	.ent	pop
	.type	pop, @function
pop:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	lw	$2,8($fp)
	slt	$2,$2,13
	beq	$2,$0,$L2
	nop

	li	$2,123			# 0x7b
	b	$L3
	nop

$L2:
	li	$2,51			# 0x33
$L3:
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	pop
	.size	pop, .-pop
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	li	$2,143			# 0x8f
	sw	$2,28($fp)
	sw	$0,24($fp)
	b	$L5
	nop

$L8:
	lw	$4,28($fp)
	.option	pic0
	jal	pop
	nop

	.option	pic2
	move	$3,$2
	lw	$2,24($fp)
	addu	$2,$2,$3
	sw	$2,24($fp)
	b	$L6
	nop

$L7:
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L6:
	lw	$2,24($fp)
	slt	$2,$2,31
	bne	$2,$0,$L7
	nop

	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L5:
	lw	$2,24($fp)
	slt	$2,$2,123
	bne	$2,$0,$L8
	nop

	lw	$2,24($fp)
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
