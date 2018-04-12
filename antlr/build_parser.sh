
ANTLR="java -Xmx500M org.antlr.v4.Tool"
GRAMMAR="C.g4"
LANGUAGE="Cpp"
OUTPUT_DIR="output"

export CLASSPATH="C:/Program Files/Java/jdk-9.0.4/bin;C:/Users/JP/Desktop/antlr/antlr4/tool/target/antlr4-4.7.2-SNAPSHOT-complete.jar"

echo "--------------------------------------"
echo "Running antlr..."
echo "Chosen grammar file : $GRAMMAR"
echo "Language selected   : $LANGUAGE"
echo "Output directory    : $OUTPUT_DIR"
$ANTLR $GRAMMAR -Dlanguage=$LANGUAGE -o $OUTPUT_DIR
echo "Done"
