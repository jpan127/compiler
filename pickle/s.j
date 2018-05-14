.class public s
.super java/lang/Object

.field private static _runTimer LRunTimer;

; intfizz_counter=0;

.field private static fizz_counter I
; intbuzz_counter=0;

.field private static buzz_counter I
; intfizz=5;

.field private static fizz I
; intbuzz=3;

.field private static buzz I
; intfizz_buzz=fizz*buzz;

.field private static fizz_buzz I
; doubled=100;

.field private static d D
; doublee=1.1;

.field private static e D
.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        s/_runTimer LRunTimer;
	; fizz_counter=0
	ldc 0
	putstatic	s/fizz_counter I
	; buzz_counter=0
	ldc 0
	putstatic	s/buzz_counter I
	; fizz=5
	ldc 5
	putstatic	s/fizz I
	; buzz=3
	ldc 3
	putstatic	s/buzz I
	; fizz_buzz=fizz*buzz
	getstatic	s/fizz I
	getstatic	s/buzz I
	imul
	putstatic	s/fizz_buzz I
	; d=100
	ldc2_w 100.0
	putstatic	s/d D
	; e=1.1
	ldc2_w 1.1
	putstatic	s/e D

; while(d>0){if(d%fizz_buzz==0){e**;fizz_counter++;}elseif(d%fizz==0){}elseif(d%buzz==0){buzz_counter++;}else{}d--;}
while_0:
	; d > 0
	getstatic	s/d D
	d2i
	ldc 0
	; Exit [while_0] condition
	if_icmple while_0_end
; if(d%fizz_buzz==0){e**;fizz_counter++;}
if_1:
	; d%fizz_buzz == 0
	getstatic	s/d D
	getstatic	s/fizz_buzz I
	i2d
	drem
	d2i
	ldc 0
	; Exit [if_1] condition
	if_icmpne if_1_end
	; e**
	getstatic	s/e D
	dup2
	dmul
	putstatic	s/e D
	; fizz_counter++
	getstatic	s/fizz_counter I
	iconst_1
	iadd
	putstatic	s/fizz_counter I
	; Exit if-else statement
	goto if_else_end_1
if_1_end:

; elseif(d%fizz==0){}
else_if_1_0:
	; d%fizz == 0
	getstatic	s/d D
	getstatic	s/fizz I
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_0] condition
	if_icmpne else_if_1_0_end
	; Exit if-else statement
	goto if_else_end_1
else_if_1_0_end:

; elseif(d%buzz==0){buzz_counter++;}
else_if_1_1:
	; d%buzz == 0
	getstatic	s/d D
	getstatic	s/buzz I
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_1] condition
	if_icmpne else_if_1_1_end
	; buzz_counter++
	getstatic	s/buzz_counter I
	iconst_1
	iadd
	putstatic	s/buzz_counter I
	; Exit if-else statement
	goto if_else_end_1
else_if_1_1_end:

; else{}
else_1:
if_else_end_1:

	; d--
	getstatic	s/d D
	dconst_1
	dsub
	putstatic	s/d D
	; Jump to start of loop
	goto while_0
while_0_end:


	getstatic     s/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
