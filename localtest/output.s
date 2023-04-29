; function "__init" with 0 parameters and 0 local vars
__init:
    iloadc 0               ; 1
    istoreg 0              ; a = 1;
    iloadc 1               ; 10
    istoreg 1              ; b = 10;
    return                 ; return;

; imported fun "printInt" at index 0
; imported fun "printNewlines" at index 1
; global var "a" at index 0
; global var "b" at index 1
; function "bar" with 0 parameters and 1 local vars
bar:
    esr 1
                           ; local var "_a_1" at index 0
    iloadg 0               ; a
    iloadc 0               ; 1
    iadd                   ; +
    istore 0               ; _a_1 = (a + 1);
    isrg                   ; printInt
    iload_0                ; _a_1
    jsre 0                 ; printInt(_a_1)
    isrg                   ; printNewlines
    iloadc 0               ; 1
    jsre 1                 ; printNewlines(1)
    return                 ; return;

; function "main" with 0 parameters and 0 local vars
main:
    isrg                   ; bar
    jsr 0 bar              ; bar()
    iloadc 2               ; 0
    ireturn                ; return 0;

.const int 1               ; index 0
.const int 10              ; index 1
.const int 0               ; index 2
.exportfun "__init" void __init
.exportfun "main" int main
.global int
.global int
.importfun "printInt" void int
.importfun "printNewlines" void int
