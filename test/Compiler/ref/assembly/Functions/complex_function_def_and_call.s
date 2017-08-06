	.file	1 "complex_function_def_and_call.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	zz
	.set	nomips16
	.set	nomicromips
	.ent	zz
	.type	zz, @function
zz:
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
	sw	$6,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	addu	$3,$3,$2
	lw	$2,16($fp)
	subu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	zz
	.size	zz, .-zz
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,56,$31		# vars= 24, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	move	$fp,$sp
	li	$2,3			# 0x3
	sw	$2,28($fp)
	li	$2,5			# 0x5
	sw	$2,32($fp)
	li	$2,13			# 0xd
	sw	$2,36($fp)
	lw	$6,36($fp)
	lw	$5,32($fp)
	lw	$4,28($fp)
	.option	pic0
	jal	zz
	nop

	.option	pic2
	sw	$2,40($fp)
	lw	$3,28($fp)
	lw	$2,32($fp)
	addu	$3,$3,$2
	lw	$2,36($fp)
	addu	$2,$3,$2
	sw	$2,44($fp)
	lw	$3,40($fp)
	lw	$2,44($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$31,52($sp)
	lw	$fp,48($sp)
	addiu	$sp,$sp,56
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
