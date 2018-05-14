.class public HELLOOOOOOO_WORRRRRLD
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method


; intfizz_counter=0;

.field private static fizz_counter I = 0

; intbuzz_counter=0;

.field private static buzz_counter I = 0

; intfizz=5;

.field private static fizz I = 5

; intbuzz=3;

.field private static buzz I = 3

; intfizz_buzz=fizz*buzz;

.field private static fizz_buzz I = fizz*buzz

; doubled=1000000;

.field private static d D = 1000000

; doublee=2;

.field private static e D = 2
.method public static main()V
; voidmain(){intfizz_counter=0;intbuzz_counter=0;intfizz=5;intbuzz=3;intfizz_buzz=fizz*buzz;doubled=1000000;doublee=2;while(d>0){if(d%fizz_buzz==0){fizz_counter++;buzz_counter++;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){buzz_counter++;}else{e**;}d--;}}

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        HELLOOOOOOO_WORRRRRLD/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        HELLOOOOOOO_WORRRRRLD/_standardIn LPascalTextIn;
	; fizz_counter=0
	ldc 0
	putstatic	HELLOOOOOOO_WORRRRRLD/fizz_counter I
	; buzz_counter=0
	ldc 0
	putstatic	HELLOOOOOOO_WORRRRRLD/buzz_counter I
	; fizz=5
	ldc 5
	putstatic	HELLOOOOOOO_WORRRRRLD/fizz I
	; buzz=3
	ldc 3
	putstatic	HELLOOOOOOO_WORRRRRLD/buzz I
	; fizz_buzz=fizz*buzz
	getstatic	HELLOOOOOOO_WORRRRRLD/fizz I
	getstatic	HELLOOOOOOO_WORRRRRLD/buzz I
	imul
	putstatic	HELLOOOOOOO_WORRRRRLD/fizz_buzz I
	; d=1000000
	ldc 1000000
	putstatic	HELLOOOOOOO_WORRRRRLD/d D
	; e=2
	ldc 2
	putstatic	HELLOOOOOOO_WORRRRRLD/e D

; while(d>0){if(d%fizz_buzz==0){fizz_counter++;buzz_counter++;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){buzz_counter++;}else{e**;}d--;}
while_0:
	; d > 0
	getstatic	HELLOOOOOOO_WORRRRRLD/d D
	ldc 0
	; Exit [while_0] condition
	if_icmple while_0_end
; if(d%fizz_buzz==0){fizz_counter++;buzz_counter++;}
if_1:
	; d%fizz_buzz == 0
	getstatic	HELLOOOOOOO_WORRRRRLD/d D
	getstatic	HELLOOOOOOO_WORRRRRLD/fizz_buzz I
	lrem
	ldc 0
	; Exit [if_1] condition
	if_icmpne if_1_end
	; fizz_counter++
	getstatic	HELLOOOOOOO_WORRRRRLD/fizz_counter I
	iconst_1
	iadd
	putstatic	HELLOOOOOOO_WORRRRRLD/fizz_counter I
	; buzz_counter++
	getstatic	HELLOOOOOOO_WORRRRRLD/buzz_counter I
	iconst_1
	iadd
	putstatic	HELLOOOOOOO_WORRRRRLD/buzz_counter I
	; Exit if-else statement
	goto if_else_end_1
if_1_end:

; elseif(d%fizz==0){fizz_counter++;}
else_if_1_0:
	; d%fizz == 0
	getstatic	HELLOOOOOOO_WORRRRRLD/d D
	getstatic	HELLOOOOOOO_WORRRRRLD/fizz I
	lrem
	ldc 0
	; Exit [else_if_1_0] condition
	if_icmpne else_if_1_0_end
	; fizz_counter++
	getstatic	HELLOOOOOOO_WORRRRRLD/fizz_counter I
	iconst_1
	iadd
	putstatic	HELLOOOOOOO_WORRRRRLD/fizz_counter I
	; Exit if-else statement
	goto if_else_end_1
else_if_1_0_end:

; elseif(d%buzz==0){buzz_counter++;}
else_if_1_1:
	; d%buzz == 0
	getstatic	HELLOOOOOOO_WORRRRRLD/d D
	getstatic	HELLOOOOOOO_WORRRRRLD/buzz I
	lrem
	ldc 0
	; Exit [else_if_1_1] condition
	if_icmpne else_if_1_1_end
	; buzz_counter++
	getstatic	HELLOOOOOOO_WORRRRRLD/buzz_counter I
	iconst_1
	iadd
	putstatic	HELLOOOOOOO_WORRRRRLD/buzz_counter I
	; Exit if-else statement
	goto if_else_end_1
else_if_1_1_end:

; else{e**;}
else_1:
	; e**
	getstatic	HELLOOOOOOO_WORRRRRLD/e D
	getstatic	HELLOOOOOOO_WORRRRRLD/e D
	lmul
	putstatic	HELLOOOOOOO_WORRRRRLD/e D
if_else_end_1:

	; d--
	getstatic	HELLOOOOOOO_WORRRRRLD/d D
	iconst_1
	lsub
	putstatic	HELLOOOOOOO_WORRRRRLD/d D
	; Jump to start of loop
	goto while_0
while_0_end:


	getstatic     HELLOOOOOOO_WORRRRRLD/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
