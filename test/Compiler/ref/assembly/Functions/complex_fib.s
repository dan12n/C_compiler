	.file	1 "complex_fib.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	fibonacci_recursive
	.set	nomips16
	.set	nomicromips
	.ent	fibonacci_recursive
	.type	fibonacci_recursive, @function
fibonacci_recursive:
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
	sw	$4,40($fp)
	lw	$2,40($fp)
	bne	$2,$0,$L2
	nop

	move	$2,$0
	b	$L3
	nop

$L2:
	lw	$3,40($fp)
	li	$2,1			# 0x1
	bne	$3,$2,$L4
	nop

	li	$2,1			# 0x1
	b	$L3
	nop

$L4:
	lw	$2,40($fp)
	addiu	$2,$2,-1
	move	$4,$2
	.option	pic0
	jal	fibonacci_recursive
	nop

	.option	pic2
	move	$16,$2
	lw	$2,40($fp)
	addiu	$2,$2,-2
	move	$4,$2
	.option	pic0
	jal	fibonacci_recursive
	nop

	.option	pic2
	addu	$2,$16,$2
$L3:
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	lw	$16,28($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	fibonacci_recursive
	.size	fibonacci_recursive, .-fibonacci_recursive
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
	li	$2,10			# 0xa
	sw	$2,28($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	fibonacci_recursive
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
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
