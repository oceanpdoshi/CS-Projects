	.file	"2.73-redo.c"
	.text
	.p2align 4,,15
	.globl	saturating_add
	.type	saturating_add, @function
saturating_add:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %eax
	xorl	%ebx, %ebx
	movl	16(%esp), %ecx
	movl	%eax, %esi
	movl	%eax, %edx
	addl	%ecx, %esi
	seto	%bl
	orl	%ecx, %edx
	negl	%ebx
	andl	$-2147483648, %edx
	andl	%ebx, %ecx
	notl	%edx
	andl	%eax, %ecx
	andl	%ebx, %edx
	sarl	$31, %ecx
	sarl	$31, %edx
	movl	%ecx, %eax
	andl	$-2147483648, %ecx
	orl	%edx, %eax
	notl	%eax
	andl	%esi, %eax
	movl	%eax, %ebx
	movl	%edx, %eax
	andl	$2147483647, %eax
	orl	%eax, %ecx
	leal	(%ebx,%ecx), %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	saturating_add, .-saturating_add
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
