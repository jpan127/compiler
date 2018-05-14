.method public static main([Ljava/lang/String;)V

    new RunTimer
    dup
    invokenonvirtual RunTimer/<init>()V
    putstatic        s/_runTimer LRunTimer;

    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "BLAAAAH %d / %f"

    iconst_2                        ; Size of array
    anewarray java/lang/Object      ; Create array

    dup                             ; Necessary not sure why
    iconst_0                        ; Pushes 0 onto the stack, necessary for indexing the array i think
    ldc 12345
    istore_1                        ; Stores top of stack into local varaiable 1
    iload_1                         ; Pushes local variable 1 onto stack
    invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
    aastore

    dup
    iconst_1
    ldc2_w 9999999.0
    dstore_2
    dload_2
    invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
    aastore                         ; Stores object reference in array

    invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
    ; pop





print_results:

    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Start:%f d:%f e:%f fizz_counter:%d buzz_counter:%d fizzbuzz:%d"
    ldc 6
    anewarray java/lang/Object

    dup
    iconst_0
    ldc2_w 20.0
    invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
    aastore

    dup
    iconst_1
    getstatic s/d D
    invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
    aastore

    dup
    iconst_2
    getstatic s/e D
    invokestatic java/lang/Double/valueOf(D)Ljava/lang/Double;
    aastore

    dup
    iconst_3
    getstatic s/fizz_counter I
    invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
    aastore

    dup
    iconst_4
    getstatic s/buzz_counter I
    invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
    aastore

    dup
    iconst_5
    getstatic s/fizz_buzz I
    invokestatic java/lang/Integer/valueOf(I)Ljava/lang/Integer;
    aastore

    invokevirtual java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
