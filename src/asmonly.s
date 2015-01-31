; Example for assembler-only program for cc65 c1p target
;
; Prints the given text and then echos the characters from the keyboard

.rodata

text:
        .byte   "OSI 65V._" ; string terminated by '_'

INPUTC      := $FD00        ; C1P character input routine
MSGBASE     := $D1E4        ; position for message text
ECHOBASE    := MSGBASE+64   ; two lines down

.code

main:
        jsr _cout       ; output string
        ldx #$00        ; initalize cursor position
_loop1:
        jsr INPUTC      ; get character from string
        sta ECHOBASE,X  ; output to screen
        inx             ; increment cursor position
        jmp _loop1

_cout:
        ldx #$00        ; initialize index into string
_loop2:
        lda text,X      ; load character from string
        cmp #'_'        ; string is terminated with '_'
        beq _end
        sta MSGBASE,X   ; output character to screen
        inx             ; increment cursor position
        jmp _loop2      ; start over
_end:
        rts
