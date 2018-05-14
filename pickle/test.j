.class public test
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

.method public static main([Ljava/lang/String;)V

    new RunTimer
    dup
    invokenonvirtual RunTimer/<init>()V
    putstatic        test/_runTimer LRunTimer;
    ; new PascalTextIn
    ; dup
    ; invokenonvirtual PascalTextIn/<init>()V
    ; putstatic        test/_standardIn LPascalTextIn;

    getstatic     test/_runTimer LRunTimer;
    invokevirtual RunTimer.printElapsedTime()V

    return

.limit locals 16
.limit stack 16
.end method
