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


; doublex


.method public static main([Ljava/lang/String;)V

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
	; Initializing argument to zero - x
	ldc2_w 0.0
	dstore 2
	; fizz_counter=0
	ldc 0
	istore 4
	; buzz_counter=0
	ldc 0
	istore 5
	; fizz=5
	ldc 5
	istore 6
	; buzz=3
	ldc 3
	istore 7
	; fizz_buzz=fizz*buzz
	iload 6
	iload 7
	imul
	istore 8
	; d=15
	ldc2_w 15.0
	dstore 9
	; e=1.1
	ldc2_w 1.1
	dstore 11

; while(d>0){if(d%fizz_buzz==0){e**;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){buzz_counter++;}else{mak1=mak1^mak2;mak2=mak2&mak3;mak3=mak3<<1;mak4=mak4*-2;}d--;}
while_0:
	; d > 0
	dload 9
	d2i
	ldc 0
	; Exit [while_0] condition
	if_icmple while_0_end
; if(d%fizz_buzz==0){e**;}
if_1:
	; d%fizz_buzz == 0
	dload 9
	iload 8
	i2d
	drem
	d2i
	ldc 0
	; Exit [if_1] condition
	if_icmpne if_1_end
	; e**
	dload 11
	dup2
	dmul
	dstore 11
	; Exit if-else statement
	goto if_else_end_1
if_1_end:

; elseif(d%fizz==0){fizz_counter++;}
else_if_1_0:
	; d%fizz == 0
	dload 9
	iload 6
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_0] condition
	if_icmpne else_if_1_0_end
	; fizz_counter++
	iload 4
	iconst_1
	iadd
	istore 4
	; Exit if-else statement
	goto if_else_end_1
else_if_1_0_end:

; elseif(d%buzz==0){buzz_counter++;}
else_if_1_1:
	; d%buzz == 0
	dload 9
	iload 7
	i2d
	drem
	d2i
	ldc 0
	; Exit [else_if_1_1] condition
	if_icmpne else_if_1_1_end
	; buzz_counter++
	iload 5
	iconst_1
	iadd
	istore 5
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
	dload 9
	dconst_1
	dsub
	dstore 9
	; Jump to start of loop
	goto while_0
while_0_end:


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
	dload 11
	invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - d
	ldc "d : %f\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	dload 9
	invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz_counter
	ldc "fizz_counter : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 4
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - x
	ldc "x : %f\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	dload 2
	invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz_buzz
	ldc "fizz_buzz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 8
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - buzz_counter
	ldc "buzz_counter : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 5
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - fizz
	ldc "fizz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 6
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - buzz
	ldc "buzz : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	iload 7
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

	getstatic     s/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 22
.limit stack 88
.end method
