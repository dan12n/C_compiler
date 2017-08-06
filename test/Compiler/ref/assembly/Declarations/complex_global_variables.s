	.file	1 "complex_global_variables.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.globl	x
	.data
	.align	2
	.type	x, @object
	.size	x, 4
x:
	.word	5
	.globl	y
	.align	2
	.type	y, @object
	.size	y, 4
y:
	.word	8
	.text
	.align	2
	.globl	r
	.set	nomips16
	.set	nomicromips
	.ent	r
	.type	r, @function
r:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	lui	$2,%hi(x)
	lw	$2,%lo(x)($2)
	addiu	$2,$2,6
	sw	$2,4($fp)
	lui	$2,%hi(x)
	li	$3,6			# 0x6
	sw	$3,%lo(x)($2)
	nop
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	r
	.size	r, .-r
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
	lui	$2,%hi(x)
	lw	$2,%lo(x)($2)
	addiu	$2,$2,1
	sw	$2,24($fp)
	lui	$2,%hi(x)
	li	$3,4			# 0x4
	sw	$3,%lo(x)($2)
	.option	pic0
	jal	r
	nop

	.option	pic2
	lui	$2,%hi(y)
	lw	$4,%lo(y)($2)
	move	$3,$4
	sll	$2,$3,2
	move	$3,$2
	sll	$2,$3,2
	subu	$2,$2,$3
	addu	$2,$2,$4
	sw	$2,28($fp)
	lui	$2,%hi(x)
	lw	$3,%lo(x)($2)
	lw	$2,28($fp)
	addu	$2,$3,$2
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
