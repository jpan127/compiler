.class public s
.super java/lang/Object

.field private static _runTimer LRunTimer;

; intmak1=128;
.field private static mak1 I


; intmak2=256;
.field private static mak2 I


; intmak3=1;
.field private static mak3 I


; intmak4=-1;
.field private static mak4 I


; floatmak5=.1;
.field private static mak5 F

.method public static fizzy(I)I
; intfizzy(intf){intnegate=f*-1;returnnegate;}

	; negate=f*-1
	iload 0
	ldc -1
	imul
	istore 1
	iload 1
	ireturn

.limit locals 22
.limit stack 8
.end method
.method public static buzzy(I)I
; intbuzzy(intb){intsquare;square=b;square**;returnsquare;}

	; square=b
	iload 0
	istore 1
	; square**
	iload 1
	dup
	imul
	istore 1
	iload 1
	ireturn

.limit locals 22
.limit stack 8
.end method

.method public static main([Ljava/lang/String;)V

	; Timer Module Instantiation
	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        s/_runTimer LRunTimer;

	; mak1=128
	ldc 128
	putstatic	s/mak1 I
	; mak2=256
	ldc 256
	putstatic	s/mak2 I
	; mak3=1
	ldc 1
	putstatic	s/mak3 I
	; mak4=-1
	ldc -1
	putstatic	s/mak4 I
	; mak5=.1
	ldc .1
	putstatic	s/mak5 F
	; fizz_counter=0
	ldc 0
	istore 0
	; buzz_counter=0
	ldc 0
	istore 1
	; fizz=5
	ldc 5
	istore 2
	; buzz=3
	ldc 3
	istore 3
	; fizz_buzz=fizz*buzz
	iload 2
	iload 3
	imul
	istore 4
	; d=100
	ldc2_w 100.0
	dstore 6
	; e=-1.1
	ldc2_w -1.1
	dstore 8

; while((d>0)and(d<1000)){if(d%fizz_buzz==0){e**;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){++buzz_counter;}else{mak1=mak1^mak2;mak2=mak2&mak3;mak3=mak3<<1;mak4=mak4*-2;}d--;}
while_0:
	; d > 0
	dload 6
	d2i
	ldc 0
	; Exit [while_0] condition
	if_icmple while_0_end
	; d < 1000
	dload 6
	d2i
	ldc 1000
	; Exit [while_0] condition
	if_icmpge while_0_end
; if(d%fizz_buzz==0){e**;}
if_1:
	; d%fizz_buzz == 0
	dload 6
	iload 4
	i2d
	drem
	d2i
	ldc 0
	; Exit [if_1] condition
	if_icmpne if_1_end
	; e**
	dload 8
	dup2
	dmul
	dstore 8
	; Exit if-else statement
	goto if_else_end_1
if_1_end:

; elseif(d%fizz==0){fizz_counter++;}
else_if_1_0:
	; d%fizz == 0
	dload 6
	iload 2
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_0] condition
	if_icmpne else_if_1_0_end
	; fizz_counter++
	iload 0
	iconst_1
	iadd
	istore 0
	; Exit if-else statement
	goto if_else_end_1
else_if_1_0_end:

; elseif(d%buzz==0){++buzz_counter;}
else_if_1_1:
	; d%buzz == 0
	dload 6
	iload 3
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_1] condition
	if_icmpne else_if_1_1_end
	; ++buzz_counter
	iload 1
	iconst_1
	iadd
	istore 1
	; Exit if-else statement
	goto if_else_end_1
else_if_1_1_end:

; else{mak1=mak1^mak2;mak2=mak2&mak3;mak3=mak3<<1;mak4=mak4*-2;}
else_1:
	; mak1=mak1^mak2
	getstatic	s/mak1 I
	getstatic	s/mak2 I
	ixor
	putstatic	s/mak1 I
	; mak2=mak2&mak3
	getstatic	s/mak2 I
	getstatic	s/mak3 I
	iand
	putstatic	s/mak2 I
	; mak3=mak3<<1
	getstatic	s/mak3 I
	ldc 1
	ishl
	putstatic	s/mak3 I
	; mak4=mak4*-2
	getstatic	s/mak4 I
	ldc -2
	imul
	putstatic	s/mak4 I
if_else_end_1:

	; d--
	dload 6
	dconst_1
	dsub
	dstore 6
	; Jump to start of loop
	goto while_0
while_0_end:

	; fizz_counter=fizzy(fizz_counter)
	iload 0
	invokestatic s/fizzy(I)I
	istore 0
	; buzz_counter=buzzy(buzz_counter)
	iload 1
	invokestatic s/buzzy(I)I
	istore 1

; Printing results of the program below
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_results:

	getstatic java/lang/System/out Ljava/io/PrintStream;
	dup
	ldc "-----------------------------------------------------------------"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

	; Printing symbol - e
	ldc "e : %f\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	dload 8
	invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - buzz_counter
	ldc "buzz_counter : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 1
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - d
	ldc "d : %f\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	dload 6
	invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz_counter
	ldc "fizz_counter : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 0
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz
	ldc "fizz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 2
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - buzz
	ldc "buzz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 3
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz_buzz
	ldc "fizz_buzz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 4
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - mak4
	ldc "mak4 : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/mak4 I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - mak5
	ldc "mak5 : %f\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/mak5 F
	invokestatic java/lang/Float/valueOf(F)Ljava/lang/Float;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - mak1
	ldc "mak1 : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/mak1 I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - mak3
	ldc "mak3 : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/mak3 I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - mak2
	ldc "mak2 : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/mak2 I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	dup
	ldc "-----------------------------------------------------------------"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	; Print Elapsed Time
	getstatic     s/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V
	return

.limit locals 32
.limit stack 48
.end method
