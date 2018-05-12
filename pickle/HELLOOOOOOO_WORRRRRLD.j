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

	putstatic	HELLOOOOOOO_WORRRRRLD/b B

; c=0

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

while0:

	getstatic     HELLOOOOOOO_WORRRRRLD/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
