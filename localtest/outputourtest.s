foo:
esr 2
iloadc 0
iloadc 1
iadd
istore 0
iload 0
iloadc 2
isub
istore 0
iload 0
iloadc 3
imul
istore 0
iload 0
iloadc 4
idiv
istore 0
iload 0
iloadc 5
irem
istore 0
iload 0
iloadc 6
ilt
bstore 1
iload 0
iloadc 7
igt
bstore 1
iload 0
iloadc 8
ile
bstore 1
iload 0
iloadc 9
ige
bstore 1
iload 0
iloadc 10
ieq
bstore 1
iload 0
iloadc 11
ine
bstore 1
iload 0
iloadc 12
ine
branch_f 1_false_expr
iload 0
iloadc 13
ige
jump 2_endce
1_false_expr:
bloadc 14
2_endce:
bstore 1
iload 0
iloadc 15
ieq
branch_f 3_false_expr
bloadc 16
jump 4_endce
3_false_expr:
iload 0
iloadc 17
ile
4_endce:
bstore 1
iload 0
ineg
istore 0
bload 1
bnot
bstore 1
iload 0
iloadc 18
ineg
isub
istore 0
iload 0
ineg
ineg
ineg
ineg
ineg
ineg
istore 0

.const int 1
.const int 2
.const int 1
.const int 45
.const int 9
.const int 4
.const int 1
.const int 2
.const int 3
.const int 4
.const int 5
.const int 6
.const int 6
.const int 4
.const bool false
.const int 6
.const bool true
.const int 4
.const int 1

