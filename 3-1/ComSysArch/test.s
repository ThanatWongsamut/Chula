	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	xzr, [sp, #8]
	add	x0, sp, #8
	mov	w1, #38
	mov	w2, #4
	bl	_posix_memalign
	cbz	w0, LBB0_2
; %bb.1:
Lloh0:
	adrp	x0, l_str@PAGE
Lloh1:
	add	x0, x0, l_str@PAGEOFF
	bl	_puts
	mov	w0, #1
	b	LBB0_3
LBB0_2:
	ldr	x8, [sp, #8]
	mov	x9, #51739
	movk	x9, #10347, lsl #16
	movk	x9, #41391, lsl #32
	movk	x9, #34492, lsl #48
	mul	x8, x8, x9
	ror	x8, x8, #1
Lloh2:
	adrp	x9, l_.str.2@PAGE
Lloh3:
	add	x9, x9, l_.str.2@PAGEOFF
Lloh4:
	adrp	x10, l_.str.1@PAGE
Lloh5:
	add	x10, x10, l_.str.1@PAGEOFF
	mov	x11, #51739
	movk	x11, #10347, lsl #16
	movk	x11, #41391, lsl #32
	movk	x11, #1724, lsl #48
	cmp	x8, x11
	csel	x0, x10, x9, lo
	mov	w8, #38
	str	x8, [sp]
	bl	_printf
	ldr	x0, [sp, #8]
	bl	_free
	mov	w0, #0
LBB0_3:
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.loh AdrpAdd	Lloh0, Lloh1
	.loh AdrpAdd	Lloh4, Lloh5
	.loh AdrpAdd	Lloh2, Lloh3
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str.1:                               ; @.str.1
	.asciz	"Memory is properly aligned to %zu bytes.\n"

l_.str.2:                               ; @.str.2
	.asciz	"Memory is not properly aligned to %zu bytes.\n"

l_str:                                  ; @str
	.asciz	"Memory allocation failed."

.subsections_via_symbols
