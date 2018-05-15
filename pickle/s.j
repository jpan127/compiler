.class public s
.super java/lang/Object

.field private static _runTimer LRunTimer;

; intbryan=0;
.field private static bryan I


; intcole=1;
.field private static cole I


; intjp=2;
.field private static jp I


; doublex


.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        s/_runTimer LRunTimer;
	; bryan=0
	ldc 0
	putstatic	s/bryan I
	; cole=1
	ldc 1
	putstatic	s/cole I
	; jp=2
	ldc 2
	putstatic	s/jp I
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
	; d=1500
	ldc2_w 1500.0
	dstore 9
	; e=1.1
	ldc2_w 1.1
	dstore 11

; while(d>0){if(d%fizz_buzz==0){e**;}elseif(d%fizz==0){fizz_counter++;}elseif(d%buzz==0){buzz_counter++;}else{}d--;}
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

; else{}
else_1:
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

	; Printing symbol - jp
	ldc "jp : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/jp I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - bryan
	ldc "bryan : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/bryan I
	invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;

	; Printing symbol - cole
	ldc "cole : %d\n"
	ldc 1
	anewarray java/lang/Object
	dup
	iconst_0
	getstatic	s/cole I
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
