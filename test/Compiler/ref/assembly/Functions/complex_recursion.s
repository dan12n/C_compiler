	.file	1 "complex_recursion.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	count_to_ten
	.set	nomips16
	.set	nomicromips
	.ent	count_to_ten
	.type	count_to_ten, @function
count_to_ten:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	lw	$2,32($fp)
	slt	$2,$2,10
	beq	$2,$0,$L2
	nop

	lw	$2,32($fp)
	addiu	$2,$2,1
	move	$4,$2
	.option	pic0
	jal	count_to_ten
	nop

	.option	pic2
$L2:
	lw	$2,32($fp)
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	count_to_ten
	.size	count_to_ten, .-count_to_ten
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 0, regs= 3/0, args= 16, gp= 8
	.mask	0xc0010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	sw	$16,28($sp)
	move	$fp,$sp
	move	$4,$0
	.option	pic0
	jal	count_to_ten
	nop

	.option	pic2
	move	$16,$2
	li	$4,1			# 0x1
	.option	pic0
	jal	count_to_ten
	nop

	.option	pic2
	addu	$16,$16,$2
	li	$4,2			# 0x2
	.option	pic0
	jal	count_to_ten
	nop

	.option	pic2
	addu	$2,$16,$2
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	lw	$16,28($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
