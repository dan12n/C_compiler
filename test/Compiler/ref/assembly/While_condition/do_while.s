	.file	1 "do_while.c"
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
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	li	$2,100			# 0x64
	sw	$2,4($fp)
	sw	$0,8($fp)
	li	$2,20			# 0x14
	sw	$2,12($fp)
$L2:
	lw	$3,4($fp)
	lw	$2,12($fp)
	subu	$2,$3,$2
	sw	$2,4($fp)
	lw	$2,8($fp)
	addiu	$2,$2,1
	sw	$2,8($fp)
	lw	$2,4($fp)
	bgez	$2,$L2
	nop

	lw	$2,8($fp)
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
