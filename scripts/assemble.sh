# set -x

REPO_PATH="C:/Users/JP/Desktop/compiler"
ASSEMBLER_PATH="$REPO_PATH/tools/jasmin-assembler"
LIBS_PATH="$REPO_PATH/libs"

# Need to use these CD commands because java would not find the jars in a different directory
START_FROM_ROOT_DIR="cd $REPO_PATH"
ASSEMBLE_CMD="cd $ASSEMBLER_PATH && java -jar "jasmin.jar" -g "../../outputs/$1.j""
EXECUTE_CMD="cd $LIBS_PATH && java -cp \".;../outputs;PascalRTL.jar\" "$1""

echo $START_FROM_ROOT_DIR
echo $ASSEMBLE_CMD
echo $EXECUTE_CMD

eval "$START_FROM_ROOT_DIR"
eval "$ASSEMBLE_CMD"
eval "$EXECUTE_CMD"