org 0000h
ljmp begin

org 000bh
cpl P2.5
reti

begin:
    mov TMOD, #02
    mov TL0, #9Ch
    mov TH0, #9Ch
    setb TR0,
    mov IP, #1
    mov IE, #82h

loop:
    sjmp loop

    end