	.file	1 "switch.c"
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
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	li	$2,2			# 0x2
	sw	$2,4($fp)
	sw	$0,0($fp)
	lw	$2,4($fp)
	li	$3,1			# 0x1
	beq	$2,$3,$L16
	nop

	slt	$3,$2,2
	beq	$3,$0,$L4
	nop

	beq	$2,$0,$L5
	nop

	b	$L2
	nop

$L4:
	li	$3,2			# 0x2
	beq	$2,$3,$L6
	nop

	li	$3,3			# 0x3
	beq	$2,$3,$L7
	nop

	b	$L2
	nop

$L5:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L8
	nop

$L6:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L8
	nop

$L7:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L8
	nop

$L2:
	lw	$2,0($fp)
	addiu	$2,$2,30
	sw	$2,0($fp)
	b	$L8
	nop

$L16:
	nop
$L8:
	li	$2,10			# 0xa
	sw	$2,4($fp)
	lw	$2,4($fp)
	slt	$3,$2,3
	beq	$3,$0,$L10
	nop

	slt	$3,$0,$2
	bne	$3,$0,$L11
	nop

	beq	$2,$0,$L12
	nop

	b	$L9
	nop

$L10:
	li	$3,3			# 0x3
	beq	$2,$3,$L13
	nop

	b	$L9
	nop

$L12:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L14
	nop

$L11:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L14
	nop

$L13:
	lw	$2,0($fp)
	addiu	$2,$2,20
	sw	$2,0($fp)
	b	$L14
	nop

$L9:
	lw	$2,0($fp)
	addiu	$2,$2,30
	sw	$2,0($fp)
$L14:
	lw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
