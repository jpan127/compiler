
ANTLR="java -Xmx500M org.antlr.v4.Tool"
GRAMMAR="C.g4"
LANGUAGE="Cpp"
OUTPUT_DIR="generated_antlr"

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

export CLASSPATH=".;$JAVA_JDK_PATH;$ANTLR_JAR_PATH/$ANTLR_JAR_FILE_NAME;"
echo "--------------------------------------"
echo "CLASSPATH = $CLASSPATH"
echo "Running antlr..."
echo "Chosen grammar file : $GRAMMAR"
echo "Language selected   : $LANGUAGE"
echo "Output directory    : $OUTPUT_DIR"
$ANTLR $GRAMMAR -Dlanguage=$LANGUAGE -o $OUTPUT_DIR
echo "Done"

java org.antlr.v4.gui.TestRig libgenerated_antlr.a primaryExpression