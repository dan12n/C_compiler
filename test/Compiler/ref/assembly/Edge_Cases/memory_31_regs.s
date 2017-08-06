	.file	1 "memory_31_regs.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,136,$31		# vars= 128, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-136
	sw	$fp,132($sp)
	move	$fp,$sp
	li	$2,1			# 0x1
	sw	$2,0($fp)
	li	$2,2			# 0x2
	sw	$2,4($fp)
	li	$2,3			# 0x3
	sw	$2,8($fp)
	li	$2,4			# 0x4
	sw	$2,12($fp)
	li	$2,5			# 0x5
	sw	$2,16($fp)
	li	$2,6			# 0x6
	sw	$2,20($fp)
	li	$2,7			# 0x7
	sw	$2,24($fp)
	li	$2,8			# 0x8
	sw	$2,28($fp)
	li	$2,9			# 0x9
	sw	$2,32($fp)
	li	$2,10			# 0xa
	sw	$2,36($fp)
	li	$2,11			# 0xb
	sw	$2,40($fp)
	li	$2,12			# 0xc
	sw	$2,44($fp)
	li	$2,13			# 0xd
	sw	$2,48($fp)
	li	$2,14			# 0xe
	sw	$2,52($fp)
	li	$2,15			# 0xf
	sw	$2,56($fp)
	li	$2,16			# 0x10
	sw	$2,60($fp)
	li	$2,17			# 0x11
	sw	$2,64($fp)
	li	$2,18			# 0x12
	sw	$2,68($fp)
	li	$2,19			# 0x13
	sw	$2,72($fp)
	li	$2,20			# 0x14
	sw	$2,76($fp)
	li	$2,21			# 0x15
	sw	$2,80($fp)
	li	$2,22			# 0x16
	sw	$2,84($fp)
	li	$2,23			# 0x17
	sw	$2,88($fp)
	li	$2,24			# 0x18
	sw	$2,92($fp)
	li	$2,25			# 0x19
	sw	$2,96($fp)
	li	$2,26			# 0x1a
	sw	$2,100($fp)
	li	$2,27			# 0x1b
	sw	$2,104($fp)
	li	$2,28			# 0x1c
	sw	$2,108($fp)
	li	$2,29			# 0x1d
	sw	$2,112($fp)
	li	$2,30			# 0x1e
	sw	$2,116($fp)
	li	$2,31			# 0x1f
	sw	$2,120($fp)
	li	$2,32			# 0x20
	sw	$2,124($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$fp,132($sp)
	addiu	$sp,$sp,136
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
