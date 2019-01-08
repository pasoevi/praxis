	.file	"distance.c"
	.text
	.globl	min2
	.type	min2, @function
min2:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L2
	movl	-4(%rbp), %eax
	jmp	.L3
.L2:
	movl	-8(%rbp), %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	min2, .-min2
	.globl	min3
	.type	min3, @function
min3:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	min2
	movl	%eax, -4(%rbp)
	movl	-28(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	min2
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	min3, .-min3
	.globl	levensteinDistance
	.type	levensteinDistance, @function
levensteinDistance:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	addq	$-128, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%rsp, %rax
	movq	%rax, %r12
	movq	-104(%rbp), %rax
	cmpq	-112(%rbp), %rax
	jne	.L7
	movl	$0, %eax
	jmp	.L8
.L7:
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movl	%eax, -44(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movl	%eax, -48(%rbp)
	cmpl	$0, -44(%rbp)
	je	.L9
	cmpl	$0, -48(%rbp)
	jne	.L10
.L9:
	movl	$0, %eax
	jmp	.L8
.L10:
	movl	-48(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -56(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -128(%rbp)
	movq	$0, -120(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -144(%rbp)
	movq	$0, -136(%rbp)
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -64(%rbp)
	movl	-48(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -160(%rbp)
	movq	$0, -152(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r13
	movl	$0, %r14d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -80(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L11
.L12:
	movq	-64(%rbp), %rax
	movl	-36(%rbp), %edx
	movslq	%edx, %rdx
	movl	-36(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -36(%rbp)
.L11:
	movl	-36(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L12
	movl	$0, -36(%rbp)
	jmp	.L13
.L18:
	movl	-36(%rbp), %eax
	leal	1(%rax), %edx
	movq	-80(%rbp), %rax
	movl	%edx, (%rax)
	movl	$0, -40(%rbp)
	jmp	.L14
.L15:
	movl	-36(%rbp), %eax
	movslq	%eax, %rdx
	movq	-104(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movl	-40(%rbp), %eax
	movslq	%eax, %rcx
	movq	-112(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -84(%rbp)
	movl	-40(%rbp), %eax
	leal	1(%rax), %ebx
	movq	-64(%rbp), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	-84(%rbp), %eax
	leal	(%rdx,%rax), %esi
	movl	-40(%rbp), %eax
	leal	1(%rax), %edx
	movq	-64(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	leal	1(%rax), %ecx
	movq	-80(%rbp), %rax
	movl	-36(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	addl	$1, %eax
	movl	%esi, %edx
	movl	%ecx, %esi
	movl	%eax, %edi
	call	min3
	movl	%eax, %ecx
	movq	-80(%rbp), %rax
	movslq	%ebx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -40(%rbp)
.L14:
	movl	-40(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L15
	movl	$0, -40(%rbp)
	jmp	.L16
.L17:
	movq	-80(%rbp), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-64(%rbp), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -40(%rbp)
.L16:
	movl	-40(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L17
	addl	$1, -36(%rbp)
.L13:
	movl	-36(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L18
	movq	-80(%rbp), %rax
	movl	-48(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
.L8:
	movq	%r12, %rsp
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	levensteinDistance, .-levensteinDistance
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
