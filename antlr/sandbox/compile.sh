COMPILE="g++ -std=c++11             \
            -I.                     \
            -Isrc                   \
            -Isrc/atn               \
            -Isrc/dfa               \
            -Isrc/misc              \
            -Isrc/support           \
            -Isrc/tree              \
            -Isrc/tree/pattern      \
            -Isrc/tree/xpath        \
            -I. -c -g               \
            main.cpp"
            # *.cpp                   \
            # src/*.cpp               \
            # src/atn/*.cpp           \
            # src/dfa/*.cpp           \
            # src/misc/*.cpp          \
            # src/support/*.cpp       \
            # src/tree/*.cpp          \
            # src/tree/pattern/*.cpp  \
            # src/tree/xpath/*.cpp"

echo $COMPILE
$COMPILE