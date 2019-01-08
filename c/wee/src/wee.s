	.file	"wee.c"
	.text
	.globl	lookup
	.type	lookup, @function
lookup:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	lookup, .-lookup
	.section	.rodata
.LC0:
	.string	"/home/sergi/.weehist"
	.align 8
.LC1:
	.string	"Option -%c requires an argument.\n"
.LC2:
	.string	"Unknown option `-%c'.\n"
	.align 8
.LC3:
	.string	"Unknown option character `\\x%x'.\n"
.LC4:
	.string	"hbc:"
	.align 8
.LC5:
	.string	"addhistflag = %d, bflag = %d, cvalue = %s\n"
.LC6:
	.string	"Non-option argument %s\n"
.LC7:
	.string	"error: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	$.LC0, -32(%rbp)
	movq	$0, -16(%rbp)
	movl	$0, opterr(%rip)
	jmp	.L4
.L15:
	movl	-36(%rbp), %eax
	cmpl	$98, %eax
	je	.L6
	cmpl	$98, %eax
	jg	.L7
	cmpl	$63, %eax
	je	.L8
	jmp	.L5
.L7:
	cmpl	$99, %eax
	je	.L9
	cmpl	$104, %eax
	jne	.L5
	movl	$1, -4(%rbp)
	jmp	.L4
.L6:
	movl	$1, -8(%rbp)
	jmp	.L4
.L9:
	movq	optarg(%rip), %rax
	movq	%rax, -16(%rbp)
	jmp	.L4
.L8:
	movl	optopt(%rip), %eax
	cmpl	$99, %eax
	jne	.L11
	movl	optopt(%rip), %edx
	movq	stderr(%rip), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L12
.L11:
	call	__ctype_b_loc
	movq	(%rax), %rax
	movl	optopt(%rip), %edx
	movslq	%edx, %rdx
	addq	%rdx, %rdx
	addq	%rdx, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	andl	$16384, %eax
	testl	%eax, %eax
	je	.L13
	movl	optopt(%rip), %edx
	movq	stderr(%rip), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	jmp	.L12
.L13:
	movl	optopt(%rip), %edx
	movq	stderr(%rip), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
.L12:
	movl	$1, %eax
	jmp	.L14
.L5:
	call	abort
.L4:
	movq	-64(%rbp), %rcx
	movl	-52(%rbp), %eax
	movl	$.LC4, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	getopt
	movl	%eax, -36(%rbp)
	cmpl	$-1, -36(%rbp)
	jne	.L15
	movq	-16(%rbp), %rcx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	optind(%rip), %eax
	movl	%eax, -20(%rbp)
	jmp	.L16
.L18:
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	cmpl	$0, -4(%rbp)
	je	.L17
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	add_to_history
	movl	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
.L17:
	addl	$1, -20(%rbp)
.L16:
	movl	-20(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L18
	movl	$0, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
