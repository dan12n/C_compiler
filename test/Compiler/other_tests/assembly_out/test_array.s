	.file	1 ""
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.text
	.align	2
	.globl	main

	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 24, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-40

	sw	$fp,36($sp)

	move	$fp,$sp
	movz	$31,$31,$0

	sw	$0,8($fp)
	li	$2,1			# 0x1
	sw	$2,12($fp)
	li	$2,2			# 0x2
	sw	$2,16($fp)
	li	$2,3			# 0x3
	sw	$2,20($fp)
	li	$2,4			# 0x4
	sw	$2,24($fp)
	li	$2,1			# 0x1
	sw	$2,8($fp)
	lw	$2,16($fp)
	move	$sp,$fp
	lw	$fp,36($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main

	.size	main, .-main
	.ident	"GCC: (Debian 4.4.5-8) 4.4.5"