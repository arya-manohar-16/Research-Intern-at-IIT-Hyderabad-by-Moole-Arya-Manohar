#define __SFR_OFFSET 0
#include <avr/io.h>

.global main

main:
    CBI DDRD, 2
    CBI DDRD, 3
    CBI DDRD, 4
    SBI DDRB, 5

loop:
    IN  R16, PIND        ; R16 = PIND

    MOV R17, R16
    ANDI R17, (1<<2)
    LSR R17
    LSR R17             ; R17 = A

    MOV R18, R16
    ANDI R18, (1<<3)
    LSR R18
    LSR R18
    LSR R18             ; R18 = B

    MOV R19, R16
    ANDI R19, (1<<4)
    LSR R19
    LSR R19
    LSR R19
    LSR R19             ; R19 = C

    MOV R20, R17
    OR  R20, R18
    COM R20
    ANDI R20, 0x01      ; R20 = n1 = ~(A + B)

    MOV R21, R19
    OR  R21, R20        ; R21 = n2 = C + n1

    MOV R22, R17
    AND R22, R18        ; R22 = n3 = A · B

    MOV R23, R21
    OR  R23, R22        ; R23 = n4 = n2 + n3

    MOV R24, R19
    COM R24
    ANDI R24, 0x01      ; R24 = n5 = ~C

    MOV R25, R24
    AND R25, R23
    COM R25
    ANDI R25, 0x01      ; R25 = Y

    SBRC R25, 0
    SBI PORTB, 5

    SBRS R25, 0
    CBI PORTB, 5

    RJMP loop
