# set -x

ASSEMBLE_CMD="java -jar jasmin-assembler/jasmin.jar -g "$1.j""
EXECUTE_CMD="java -cp \".;PascalRTL.jar\" "$1""

echo $ASSEMBLE_CMD
echo $EXECUTE_CMD

eval "$ASSEMBLE_CMD"
eval "$EXECUTE_CMD"