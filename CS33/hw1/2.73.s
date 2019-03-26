	.file	"2.73.c"
	.text
	.p2align 4,,15
	.globl	saturating_add
	.type	saturating_add, @function
saturating_add:
.LFB0:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %esi
	movl	20(%esp), %edi
	movl	%esi, %edx
	leal	(%esi,%edi), %eax
	orl	%edi, %edx
	andl	%edi, %esi
	movl	%eax, %ecx
	andl	$-2147483648, %edx
	andl	$-2147483648, %ecx
	notl	%edx
	andl	%ecx, %edx
	notl	%ecx
	andl	%esi, %ecx
	movl	%edx, %ebx
	sarl	$31, %ecx
	sarl	$31, %ebx
	movl	%ecx, %edx
	movl	%ebx, %ecx
	movl	%edx, %esi
	orl	%ebx, %edx
	andl	$2147483647, %ecx
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	andl	$-2147483648, %esi
	notl	%edx
	orl	%esi, %ecx
	andl	%eax, %edx
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	leal	(%ecx,%edx), %eax
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
