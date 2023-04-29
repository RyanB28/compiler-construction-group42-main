main:
esr 25
iloadc 0
iloadc 1
iadd
istore 0
floadc 2
floadc 3
fadd
fstore 1
iloadc 1
iloadc 0
isub
istore 2
floadc 4
floadc 5
fsub
fstore 3
iloadc 1
iloadc 1
imul
istore 4
floadc 6
floadc 7
fmul
fstore 5
iloadc 0
iloadc 1
idiv
istore 6
floadc 2
floadc 8
fdiv
fstore 7
iloadc 9
iloadc 10
irem
istore 8
bloadc 11
branch_f 1_false_expr
bloadc 12
jump 2_end
1_false_expr:
bloadc 13
2_end:
bstore 9
iloadc 0
iloadc 1
ilt
bstore 10
floadc 2
floadc 14
flt
bstore 11
iloadc 1
iloadc 0
igt
bstore 12
floadc 13
floadc 13
fgt
bstore 13
iloadc 0
iloadc 1
ile
bstore 14
floadc 2
floadc 13
fle
bstore 15
iloadc 1
iloadc 0
ige
bstore 16
floadc 13
floadc 2
fge
bstore 17
iloadc 0
iloadc 1
ine
bstore 18
floadc 2
floadc 13
fne
bstore 19
bloadc 11
branch_f 3_false_expr
iloadc 0
jump 4_end
3_false_expr:
iloadc 13
4_end:
bloadc 13
branch_f 5_false_expr
iloadc 0
jump 6_end
5_false_expr:
iloadc 13
6_end:
ine
bstore 20
iloadc 0
iloadc 1
ieq
bstore 21
floadc 2
floadc 2
feq
bstore 22
bloadc 11
branch_f 7_false_expr
iloadc 0
jump 8_end
7_false_expr:
iloadc 13
8_end:
bloadc 11
branch_f 9_false_expr
iloadc 0
jump 10_end
9_false_expr:
iloadc 13
10_end:
ieq
bstore 23
bloadc 11
branch_f 11_false_expr
bloadc 11
jump 12_end
11_false_expr:
bloadc 13
12_end:
bstore 24
iloadc 13
ireturn
return

.const int 1
.const int 2
.const float 1.200000
.const float 1.200000
.const float 2.500000
.const float 1.500000
.const float 2.400000
.const float 2.400000
.const float 0.500000
.const int 9
.const int 3
.const bool true
.const bool true
.const bool false
.const float 2.100000

