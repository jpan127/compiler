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


; voida;

.field private static a V

; boolb=0;

.field private static b B = 0

; doublec=0;

.field private static c D = 0

; inte=a*b;

.field private static e I = a*b

; floatd=e+e;

.field private static d F = e+e

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        HELLOOOOOOO_WORRRRRLD/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        HELLOOOOOOO_WORRRRRLD/_standardIn LPascalTextIn;

	; b=0
	iconst 0
	putstatic	HELLOOOOOOO_WORRRRRLD/b B
	; c=0
	iconst 0
	putstatic	HELLOOOOOOO_WORRRRRLD/c D
	; e=a*b
	getstatic	HELLOOOOOOO_WORRRRRLD/a V
	getstatic	HELLOOOOOOO_WORRRRRLD/b B
	imul
	putstatic	HELLOOOOOOO_WORRRRRLD/e I
	; d=e+e
	getstatic	HELLOOOOOOO_WORRRRRLD/e I
	getstatic	HELLOOOOOOO_WORRRRRLD/e I
	iadd
	putstatic	HELLOOOOOOO_WORRRRRLD/d F
	; d=12345
	iconst 12345
	putstatic	HELLOOOOOOO_WORRRRRLD/d F

while_0:
	; d > 0
	getstatic	HELLOOOOOOO_WORRRRRLD/d F
	iconst 0
	; Exit [while_0] condition
	if_icmple while_0_end
	; e=5
	iconst 5
	putstatic	HELLOOOOOOO_WORRRRRLD/e I
	; Jump to start of loop
	goto while_0
while_0_end:

	getstatic     HELLOOOOOOO_WORRRRRLD/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
