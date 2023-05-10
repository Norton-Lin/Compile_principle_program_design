	.text
	.file	"main"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %r15, -16
	movq	x@GOTPCREL(%rip), %rbx
	movl	$0, (%rbx)
	callq	readarray@PLT
	xorl	%edi, %edi
	movl	$4, %esi
	callq	quicksort@PLT
	movl	(%rbx), %eax
	cmpl	$5, %eax
	setl	15(%rsp)
	cmpl	$4, %eax
	jg	.LBB0_3
	movq	y@GOTPCREL(%rip), %r14
	movq	a@GOTPCREL(%rip), %r15
	.p2align	4, 0x90
.LBB0_2:
	movslq	(%rbx), %rax
	movl	(%r15,%rax,4), %edi
	movl	%edi, (%r14)
	callq	write_int@PLT
	movl	(%rbx), %eax
	incl	%eax
	movl	%eax, (%rbx)
	cmpl	$5, %eax
	setl	15(%rsp)
	jl	.LBB0_2
.LBB0_3:
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	readarray
	.p2align	4, 0x90
	.type	readarray,@function
readarray:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movl	$0, 4(%rsp)
	movb	$1, 3(%rsp)
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB1_3
	movq	y@GOTPCREL(%rip), %r14
	movq	a@GOTPCREL(%rip), %rbx
	.p2align	4, 0x90
.LBB1_2:
	callq	read_int@PLT
	movl	%eax, (%r14)
	movslq	4(%rsp), %rcx
	movl	%eax, (%rbx,%rcx,4)
	movl	4(%rsp), %eax
	incl	%eax
	movl	%eax, 4(%rsp)
	cmpl	$5, %eax
	setl	3(%rsp)
	jl	.LBB1_2
.LBB1_3:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	readarray, .Lfunc_end1-readarray
	.cfi_endproc

	.globl	quicksort
	.p2align	4, 0x90
	.type	quicksort,@function
quicksort:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -16(%rbp)
	movslq	%edi, %rcx
	movl	%ecx, -8(%rbp)
	movl	%esi, -4(%rbp)
	movq	a@GOTPCREL(%rip), %rdi
	movl	(%rdi,%rcx,4), %edx
	movl	%edx, -12(%rbp)
	cmpl	%esi, %ecx
	jge	.LBB2_8
	movl	-4(%rbp), %edx
	movq	%rsp, %rsi
	leaq	-16(%rsi), %r8
	movq	%r8, %rsp
	cmpl	%edx, -8(%rbp)
	setl	-16(%rsi)
	jl	.LBB2_2
.LBB2_7:
	movslq	-8(%rbp), %rcx
	movl	-12(%rbp), %edx
	movl	%edx, (%rdi,%rcx,4)
	movl	-20(%rbp), %edi
	leal	-1(%rcx), %esi
	callq	quicksort@PLT
	movl	-4(%rbp), %edi
	incl	%edi
	movl	-16(%rbp), %esi
	callq	quicksort@PLT
	jmp	.LBB2_9
	.p2align	4, 0x90
.LBB2_6:
	movslq	-4(%rbp), %rax
	movslq	-8(%rbp), %rcx
	movl	(%rdi,%rcx,4), %edx
	movl	%edx, (%rdi,%rax,4)
	cmpl	%eax, %ecx
	setl	(%r8)
	jge	.LBB2_7
.LBB2_2:
	movslq	-4(%rbp), %rdx
	movl	(%rdi,%rdx,4), %esi
	cmpl	-12(%rbp), %esi
	setge	%sil
	cmpl	%edx, -8(%rbp)
	setl	%cl
	andb	%sil, %cl
	movq	%rsp, %rsi
	leaq	-16(%rsi), %rdx
	movq	%rdx, %rsp
	testb	%cl, %cl
	movb	%cl, -16(%rsi)
	je	.LBB2_4
	.p2align	4, 0x90
.LBB2_3:
	movl	-4(%rbp), %ecx
	decl	%ecx
	movl	%ecx, -4(%rbp)
	movslq	%ecx, %rcx
	movl	(%rdi,%rcx,4), %esi
	cmpl	-12(%rbp), %esi
	setge	%al
	cmpl	%ecx, -8(%rbp)
	setl	%cl
	andb	%al, %cl
	movb	%cl, (%rdx)
	jne	.LBB2_3
.LBB2_4:
	movslq	-8(%rbp), %rax
	movslq	-4(%rbp), %rcx
	movl	(%rdi,%rcx,4), %edx
	movl	%edx, (%rdi,%rax,4)
	cmpl	-12(%rbp), %edx
	setle	%dl
	cmpl	%ecx, %eax
	setl	%al
	andb	%dl, %al
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rdx
	movq	%rdx, %rsp
	testb	%al, %al
	movb	%al, -16(%rcx)
	je	.LBB2_6
	.p2align	4, 0x90
.LBB2_5:
	movl	-8(%rbp), %eax
	incl	%eax
	movl	%eax, -8(%rbp)
	cltq
	movl	(%rdi,%rax,4), %ecx
	cmpl	-12(%rbp), %ecx
	setle	%cl
	cmpl	-4(%rbp), %eax
	setl	%al
	andb	%cl, %al
	movb	%al, (%rdx)
	jne	.LBB2_5
	jmp	.LBB2_6
.LBB2_8:
	movl	$0, -24(%rbp)
.LBB2_9:
	movq	%rbp, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	quicksort, .Lfunc_end2-quicksort
	.cfi_endproc

	.section	".note.GNU-stack","",@progbits
