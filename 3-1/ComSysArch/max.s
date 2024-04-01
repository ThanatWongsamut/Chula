	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_max1                           ; -- Begin function max1
	.p2align	2
_max1:                                  ; @max1
	.cfi_startproc
; %bb.0:
	cmp	w0, w1
	csel	w0, w0, w1, gt
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_max2                           ; -- Begin function max2
	.p2align	2
_max2:                                  ; @max2
	.cfi_startproc
; %bb.0:
	cmp	w0, w1
	csel	w0, w0, w1, gt
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
