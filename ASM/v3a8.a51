    org 0000h           ; Vectortabelle ueberspringen           
    ljmp begin           

    org 000bh           ; Adresse auf Timer0 subroutine (Vectortabelle) setzen
    cpl P2.5            ; P2.5 toggeln
    reti                ; Interruptroutine verlassen

begin:
    mov TMOD, #02       ; Timer modus (auto-reload, TMOD = 00000010b)
    setb PT0            ; Timer 0 interrupt prioritaet (hoechste)
    setb EA             ; Interrupts zulassen (IE = 10000000b)
    setb ET0            ; Interrupt fuer timer 0 aktivieren (IE = 10000010b)
    mov TL0, #9Ch       ; Timer low register auf 156 (zaehler, 256 - 156 = 100)
    mov TH0, #9Ch       ; Timer high register auf 156 (bei overflow TH0 -> TL0)
    setb TR0            ; Timer0 starten (TR0 = 1)
    
loop:
    mov R0, #90h        ; Adresse 90h in R0 laden (LSByte)
    mov A, @R0          ; Wert von 90h in A
    add A, #01h         ; A inkrementieren
    mov @R0, A          ; A bei Adresse 90h speichern
    
    mov R0, #91h        ; Adresse 91h in R0
    mov A, @R0          ; Wert von 91h in R0
    addc A, #00h        ; Carry addieren
    mov @R0, A          ; A bei Adresse 91h speichern
    
    mov R0, #92h        ; Adresse 92h in R0 laden (MSByte)
    mov A, @R0          ; Wert von 92h in A
    addc A, #00h        ; Carry addieren
    mov @R0, A          ; A bei Adresse 92h speichern
    
    jmp loop            ; Zum Anfang springen
    end                 ; Ende