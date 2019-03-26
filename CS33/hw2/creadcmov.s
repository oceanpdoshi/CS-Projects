	.file	"creadcmov.c"
	.text
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	movq	$-1, -8(%rsp)
	leaq	-8(%rdi), %rdx
	leaq	-8(%rsp), %rax
	testq	%rdi, %rdi
	cmovne	%rdx, %rax
	movq	(%rax), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
