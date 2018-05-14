.source s.j
.class public s
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;

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

; doubled=1000000;

.field private static d D

; doublee=2;

.field private static e F

.method public <init>()V

    aload_0
    invokenonvirtual    java/lang/Object/<init>()V
    return

.limit locals 1
.limit stack 1
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        s/_runTimer LRunTimer;

    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "BLAAAAH %d / %f"
    ; invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
    iconst_2
    anewarray java/lang/Object
    dup
    iconst_0
    ldc 12345
    istore_1
    iload_1
    invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
    aastore
    dup
    iconst_1
    ldc2_w 9999999.0
    dstore_2
    dload_2
    invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
    aastore
    invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
    ; pop

	; ; fizz_counter=0
	; ldc 0
	; putstatic	s/fizz_counter I
	; ; buzz_counter=0
	; ldc 0
	; putstatic	s/buzz_counter I
	; ; fizz=5
	; ldc 5
	; putstatic	s/fizz I
	; ; buzz=3
	; ldc 3
	; putstatic	s/buzz I
	; ; fizz_buzz=fizz*buzz
	; getstatic	s/fizz I
	; getstatic	s/buzz I
	; imul
	; putstatic	s/fizz_buzz I
	; ; d=1000000
 ;    ldc_w   1000000
	; putstatic	s/d D

; 	; e=2
; 	ldc 2
; 	putstatic	s/e D

; ; while(d>0){if(d%fizz_buzz==0){fizz_counter++;buzz_counter++;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){buzz_counter++;}else{e**;}d--;}
; while_0:
; 	; d > 0
; 	getstatic	s/d D
; 	ldc 0
; 	; Exit [while_0] condition
; 	if_icmple while_0_end
; ; if(d%fizz_buzz==0){fizz_counter++;buzz_counter++;}
; if_1:
; 	; d%fizz_buzz == 0
; 	getstatic	s/d D
; 	getstatic	s/fizz_buzz I
; 	lrem
; 	ldc 0
; 	; Exit [if_1] condition
; 	if_icmpne if_1_end
; 	; fizz_counter++
; 	getstatic	s/fizz_counter I
; 	iconst_1
; 	iadd
; 	putstatic	s/fizz_counter I
; 	; buzz_counter++
; 	getstatic	s/buzz_counter I
; 	iconst_1
; 	iadd
; 	putstatic	s/buzz_counter I
; 	; Exit if-else statement
; 	goto if_else_end_1
; if_1_end:

; ; elseif(d%fizz==0){fizz_counter++;}
; else_if_1_0:
; 	; d%fizz == 0
; 	getstatic	s/d D
; 	getstatic	s/fizz I
; 	lrem
; 	ldc 0
; 	; Exit [else_if_1_0] condition
; 	if_icmpne else_if_1_0_end
; 	; fizz_counter++
; 	getstatic	s/fizz_counter I
; 	iconst_1
; 	iadd
; 	putstatic	s/fizz_counter I
; 	; Exit if-else statement
; 	goto if_else_end_1
; else_if_1_0_end:

; ; elseif(d%buzz==0){buzz_counter++;}
; else_if_1_1:
; 	; d%buzz == 0
; 	getstatic	s/d D
; 	getstatic	s/buzz I
; 	lrem
; 	ldc 0
; 	; Exit [else_if_1_1] condition
; 	if_icmpne else_if_1_1_end
; 	; buzz_counter++
; 	getstatic	s/buzz_counter I
; 	iconst_1
; 	iadd
; 	putstatic	s/buzz_counter I
; 	; Exit if-else statement
; 	goto if_else_end_1
; else_if_1_1_end:

; ; else{e**;}
; else_1:
; 	; e**
; 	getstatic	s/e D
; 	getstatic	s/e D
; 	lmul
; 	putstatic	s/e D
; if_else_end_1:

; 	; d--
; 	getstatic	s/d D
; 	iconst_1
; 	lsub
; 	putstatic	s/d D
; 	; Jump to start of loop
; 	goto while_0
; while_0_end:


	getstatic     s/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
