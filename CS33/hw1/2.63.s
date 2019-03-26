	.file	"2.63.c"
	.text
	.p2align 4,,15
	.globl	srl
	.type	srl, @function
srl:
.LFB0:
	.cfi_startproc
	movl	8(%esp), %ecx
	movl	4(%esp), %eax
	sarl	%cl, %eax
	testl	%ecx, %ecx
	je	.L1
	cmpl	$31, %ecx
	ja	.L3
	movl	$32, %edx
	subl	%ecx, %edx
	movl	%edx, %ecx
	movl	$-1, %edx
	sall	%cl, %edx
	notl	%edx
	andl	%edx, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	xorl	%eax, %eax
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	srl, .-srl
	.p2align 4,,15
	.globl	sra
	.type	sra, @function
sra:
.LFB1:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %edx
	movl	16(%esp), %ecx
	movl	%edx, %eax
	shrl	%cl, %eax
	testl	%ecx, %ecx
	je	.L8
	cmpl	$31, %ecx
	ja	.L10
	testl	%edx, %edx
	jg	.L8
	movl	$32, %ebx
	movl	$1, %esi
	subl	%ecx, %ebx
	movl	%ebx, %ecx
	movl	$-1, %ebx
	sall	%cl, %esi
	sall	%cl, %ebx
	testl	%edx, %esi
	setne	%dl
	movzbl	%dl, %edx
	negl	%edx
	andl	%ebx, %edx
	orl	%edx, %eax
.L8:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	.cfi_restore_state
	xorl	%eax, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE1:
	.size	sra, .-sra
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
