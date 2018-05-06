set -x

RED='\033[0;31m'
RUNTIME_ROOT_DIR="C:/Users/JP/Desktop/compiler/pickle/antlr4-runtime"

COMPILE="g++ -std=c++11                           \
            -I.                                   \
            -c                                    \
            -g                                    \
            -I$RUNTIME_ROOT_DIR                   \
            -I$RUNTIME_ROOT_DIR/atn               \
            -I$RUNTIME_ROOT_DIR/dfa               \
            -I$RUNTIME_ROOT_DIR/misc              \
            -I$RUNTIME_ROOT_DIR/support           \
            -I$RUNTIME_ROOT_DIR/tree              \
            -I$RUNTIME_ROOT_DIR/tree/pattern      \
            -I$RUNTIME_ROOT_DIR/tree/xpath        \
            $RUNTIME_ROOT_DIR/*.cpp               \
            $RUNTIME_ROOT_DIR/atn/*.cpp           \
            $RUNTIME_ROOT_DIR/dfa/*.cpp           \
            $RUNTIME_ROOT_DIR/misc/*.cpp          \
            $RUNTIME_ROOT_DIR/support/*.cpp       \
            $RUNTIME_ROOT_DIR/tree/*.cpp          \
            $RUNTIME_ROOT_DIR/tree/pattern/*.cpp  \
            $RUNTIME_ROOT_DIR/tree/xpath/*.cpp"

MAKE_TEMP_DIR="mkdir $RUNTIME_ROOT_DIR/temp"

MOVE_OBJECTS_TO_TEMP_DIR="mv *.o $RUNTIME_ROOT_DIR/temp"

ARCHIVE_TO_STATIC_LIB="ar -r antlr-runtime.a $RUNTIME_ROOT_DIR/temp/*.o"

####################################################################
#                      Compile Static Library                      #
####################################################################

$COMPILE
if [ ! -d "${RUNTIME_ROOT_DIR}/temp" ]; then
    $MAKE_TEMP_DIR
fi
$MOVE_OBJECTS_TO_TEMP_DIR
$ARCHIVE_TO_STATIC_LIB