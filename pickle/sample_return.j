.class public sample_return
.super java/lang/Object

.field private static _runTimer LRunTimer;

; intq


; intx


.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        sample_return/_runTimer LRunTimer;
	; x=2
	ldc 2

	istore 2

	iload 2

	invokestatic sample_return/func(I)V
	return

.limit locals 22
.limit stack 8
.end method
.method public static func(I)V
; voidfunc(intq){inty;y=3;return;}

	; y=3
	ldc 3

	istore 3

	return

.limit locals 24
.limit stack 16
.end method
.method public static returns_double(I)D
; doublereturns_double(intx){doublez;z=1.0;returnz;}

	; z=1.0
	ldc2_w 1.0

	dstore 3

	dload 3

	dreturn

.limit locals 26
.limit stack 24
.end method
