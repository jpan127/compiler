
ANTLR="java -Xmx500M org.antlr.v4.Tool"
LANGUAGE="quickanddirtyc"
GRAMMAR="$LANGUAGE.g4"
TARGET="Java"
OUTPUT_DIR="generated_java"
SAMPLE_C_FILE="hello_world.c"

# Set The path to your JAVA JDK here
JAVA_JDK_PATH="C:/Program Files/Java/jdk-9/bin"
ANTLR_JAR_PATH="C:/Users/JP/Desktop/compiler/antlr/antlr"
ANTLR_JAR_FILE_NAME="antlr-4.7-complete.jar"

# Check if your JDK path exists
if [ ! -d "$JAVA_JDK_PATH" ]; then
    echo "The path to your Java JDK is not set correctly : $JAVA_JDK_PATH"
    exit
fi

# Check if your antlr path exists
if [ ! -d "$ANTLR_JAR_PATH" ]; then
    echo "The path to your antlr is not set correctly : $ANTLR_JAR_PATH"
    exit
fi

export CLASSPATH=".;$JAVA_JDK_PATH;$ANTLR_JAR_PATH/$ANTLR_JAR_FILE_NAME;$OUTPUT_DIR;"
echo "--------------------------------------"
echo "CLASSPATH = $CLASSPATH"
echo "Running antlr..."
echo "Chosen grammar file : $GRAMMAR"
echo "Language selected   : $TARGET"
echo "Output directory    : $OUTPUT_DIR"
$ANTLR $GRAMMAR -Dlanguage=$TARGET -o $OUTPUT_DIR
echo "Done"

# Compile all
echo "Compiling java code..."
javac $OUTPUT_DIR/*.java

# Generate parse tree
echo "Running test rig..."
java org.antlr.v4.gui.TestRig $LANGUAGE compilationUnit -gui < $SAMPLE_C_FILE