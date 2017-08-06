	.file	1 "everything.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	rust
	.set	nomips16
	.set	nomicromips
	.ent	rust
	.type	rust, @function
rust:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	lw	$4,8($fp)
	move	$3,$4
	sll	$2,$3,2
	move	$3,$2
	sll	$2,$3,2
	subu	$2,$2,$3
	addu	$2,$2,$4
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	rust
	.size	rust, .-rust
	.align	2
	.globl	hola
	.set	nomips16
	.set	nomicromips
	.ent	hola
	.type	hola, @function
hola:
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
	sw	$0,28($fp)
	b	$L4
	nop

$L5:
	lw	$4,44($fp)
	.option	pic0
	jal	rust
	nop

	.option	pic2
	move	$3,$2
	lw	$2,28($fp)
	addu	$2,$3,$2
	lw	$3,40($fp)
	addu	$2,$3,$2
	sw	$2,40($fp)
	lw	$2,28($fp)
	addiu	$2,$2,1
	sw	$2,28($fp)
$L4:
	lw	$2,28($fp)
	slt	$2,$2,10
	bne	$2,$0,$L5
	nop

	lw	$2,40($fp)
	sll	$2,$2,1
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	hola
	.size	hola, .-hola
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
	li	$2,120			# 0x78
	sw	$2,24($fp)
	sw	$0,24($fp)
	b	$L8
	nop

$L10:
	li	$5,11			# 0xb
	lw	$4,24($fp)
	.option	pic0
	jal	hola
	nop

	.option	pic2
	move	$3,$2
	lw	$2,24($fp)
	addu	$2,$2,$3
	sw	$2,24($fp)
	li	$5,-31			# 0xffffffffffffffe1
	li	$4,-21			# 0xffffffffffffffeb
	.option	pic0
	jal	hola
	nop

	.option	pic2
	sw	$2,28($fp)
	lw	$2,24($fp)
	slt	$2,$2,12
	beq	$2,$0,$L9
	nop

	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
	nop
$L9:
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L8:
	lw	$2,24($fp)
	slt	$2,$2,123
	bne	$2,$0,$L10
	nop

	lw	$3,24($fp)
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
