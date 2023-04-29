; function "bar" with 1 parameters and 0 local vars
bar:
                           ; parameter "p" at index 0
    iloadc 0               ; 0
    ireturn                ; return 0;

; function "foo" with 1 parameters and 2 local vars
foo:
    esr 2
                           ; parameter "p" at index 0
                           ; local var "i" at index 1
                           ; local var "a" at index 2
    isrg                   ; bar
    iload_2                ; a
    jsr 1 bar              ; bar(a)
    ipop                   ; disregard return value
    iloadc 0               ; 0
    ireturn                ; return 0;

.const int 0               ; index 0
