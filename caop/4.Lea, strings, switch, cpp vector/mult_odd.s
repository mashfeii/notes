	.file	"mult_odd.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%esi
	pushl	%ebx
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	subl	$36, %esp
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
	leal	-32(%ebp), %eax
	pushl	%eax
	leal	.LC0@GOTOFF(%ebx), %esi
	pushl	%esi
	call	__isoc99_scanf@PLT
	movl	-32(%ebp), %edx
	addl	$12, %esp
	movl	%edx, %eax
	sall	$4, %eax
	addl	%edx, %eax
	pushl	%eax
	pushl	%esi
	pushl	$1
	call	__printf_chk@PLT
	addl	$16, %esp
	movl	-28(%ebp), %eax
	subl	%gs:20, %eax
	jne	.L5
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail_local
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB24:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE24:
	.hidden	__stack_chk_fail_local
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
