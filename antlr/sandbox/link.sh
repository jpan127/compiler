LINK="g++ -std=c++11        \
        -I.                 \
        -Isrc               \
        -Isrc/atn           \
        -Isrc/dfa           \
        -Isrc/misc          \
        -Isrc/support       \
        -Isrc/tree          \
        -Isrc/tree/pattern  \
        -Isrc/tree/xpath    \
        -static-libstdc++   \
        *.o                 \
        -L../antlr     \
        -lantlr-runtime           \
        -o Z"

echo $LINK
$LINK        