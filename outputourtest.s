printBool:
    bload 0
    branch_f 1_else
    isrg
    iloadc 0
    jsre 0
    jump 2_endie
    1_else:
    isrg
    iloadc 1
    jsre 0
    2_endie:
    isrg
    iloadc 2
    jsre 1
    return;

t:
isrg
iloadc 3
jsre 0
bloadc 4
breturn

f:
isrg
iloadc 5
jsre 0
bloadc 6
breturn


main:
isrg
isrg
jsr 0 t
isrg
jsr 0 f
beq
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 t
beq
jsr 1 printBool
isrg
isrg
jsr 0 t
isrg
jsr 0 t
beq
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 f
beq
jsr 1 printBool
isrg
iloadc 7
jsre 1
isrg
isrg
jsr 0 t
isrg
jsr 0 f
bne
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 t
bne
jsr 1 printBool
isrg
isrg
jsr 0 t
isrg
jsr 0 t
bne
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 f
bne
jsr 1 printBool
isrg
iloadc 8
jsre 1
isrg
isrg
jsr 0 t
branch_f 1_false_expr
isrg
jsr 0 f
jump 2_endce
1_false_expr:
bloadc 9
2_endce:
jsr 1 printBool
isrg
isrg
jsr 0 f
branch_f 3_false_expr
isrg
jsr 0 t
jump 4_endce
3_false_expr:
bloadc 10
4_endce:
jsr 1 printBool
isrg
isrg
jsr 0 t
branch_f 5_false_expr
isrg
jsr 0 t
jump 6_endce
5_false_expr:
bloadc 11
6_endce:
jsr 1 printBool
isrg
isrg
jsr 0 f
branch_f 7_false_expr
isrg
jsr 0 f
jump 8_endce
7_false_expr:
bloadc 12
8_endce:
jsr 1 printBool
isrg
iloadc 13
jsre 1
isrg
isrg
jsr 0 t
branch_f 9_false_expr
bloadc 14
jump 10_endce
9_false_expr:
isrg
jsr 0 f
10_endce:
jsr 1 printBool
isrg
isrg
jsr 0 f
branch_f 11_false_expr
bloadc 15
jump 12_endce
11_false_expr:
isrg
jsr 0 t
12_endce:
jsr 1 printBool
isrg
isrg
jsr 0 t
branch_f 13_false_expr
bloadc 16
jump 14_endce
13_false_expr:
isrg
jsr 0 t
14_endce:
jsr 1 printBool
isrg
isrg
jsr 0 f
branch_f 15_false_expr
bloadc 17
jump 16_endce
15_false_expr:
isrg
jsr 0 f
16_endce:
jsr 1 printBool
isrg
iloadc 18
jsre 1
isrg
isrg
jsr 0 t
isrg
jsr 0 f
bmul
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 t
bmul
jsr 1 printBool
isrg
isrg
jsr 0 t
isrg
jsr 0 t
bmul
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 f
bmul
jsr 1 printBool
isrg
iloadc 19
jsre 1
isrg
isrg
jsr 0 t
isrg
jsr 0 f
badd
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 t
badd
jsr 1 printBool
isrg
isrg
jsr 0 t
isrg
jsr 0 t
badd
jsr 1 printBool
isrg
isrg
jsr 0 f
isrg
jsr 0 f
badd
jsr 1 printBool
isrg
iloadc 20
jsre 1
isrg
iloadc 21
iloadc 22
ine
branch_f 17_false_expr
bloadc 23
jump 18_endce
17_false_expr:
bloadc 24
18_endce:
jsr 1 printBool
isrg
iloadc 25
iloadc 26
ine
branch_f 19_false_expr
bloadc 27
jump 20_endce
19_false_expr:
bloadc 28
20_endce:
jsr 1 printBool
isrg
iloadc 29
jsre 1
isrg
floadc 30
floadc 31
fne
branch_f 21_false_expr
bloadc 32
jump 22_endce
21_false_expr:
bloadc 33
22_endce:
jsr 1 printBool
isrg
floadc 34
floadc 35
fne
branch_f 23_false_expr
bloadc 36
jump 24_endce
23_false_expr:
bloadc 37
24_endce:
jsr 1 printBool
isrg
iloadc 38
jsre 1
iloadc 39
ireturn

.const int 1
.const int 0
.const int 1
.const int 1
.const bool true
.const int 0
.const bool false
.const int 1
.const int 1
.const bool false
.const bool false
.const bool false
.const bool false
.const int 1
.const bool true
.const bool true
.const bool true
.const bool true
.const int 1
.const int 1
.const int 1
.const int 5
.const int 0
.const bool true
.const bool false
.const int 0
.const int 0
.const bool true
.const bool false
.const int 1
.const float 5.000000
.const float 0.000000
.const bool true
.const bool false
.const float 0.000000
.const float 0.000000
.const bool true
.const bool false
.const int 1
.const int 0

.exportfun "main" int  main
.importfun "printInt" void int 
.importfun "printNewlines" void int 
