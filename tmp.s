__init:
iloadc 0
istoreg 0
iloadc 1
istoreg 1
return
bar:
esr 1
iloadg 0
iloadc 2
iadd
istore 0
isrg
iload 0
jsre 0
isrg
iloadc 3
jsre 1
return
main:
isrg
jsr 0 bar
iloadc 4
ireturn
return

.const int 1
.const int 10
.const int 1
.const int 1
.const int 0

.global int 
.global int 
.exportfun "__init" void  __init
.exportfun "main" int  main
.importfun "printInt" void int 
.importfun "printNewlines" void int 
