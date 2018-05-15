.class public sample_return
.super java/lang/Object

.field private static _runTimer LRunTimer;

; intx


.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        sample_return/_runTimer LRunTimer;
	; x=2
	ldc 2
	istore 2istore 2
	iload 2iload 2

	ireturn

.limit locals 2
.limit stack 8
.end method
.method public static func()V
; voidfunc(){inty;y=3;return;}

	; y=3
	ldc 3
	istore 2

return

.limit locals 2
.limit stack 8
.end method
.method public static returns_double(I)D
; doublereturns_double(intx){doublez;z=1.0;returnz;}

	; z=1.0
	ldc2_w 1.0
	dstore 3
	dload 3

	dreturn

.limit locals 6
.limit stack 24
.end method
