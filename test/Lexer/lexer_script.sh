#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
cd ../../
make clean
echo " Force building histogram"
make bin/c_lexer
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""
mkdir -p test/Lexer/out
mkdir -p test/Lexer/in_preprocessor

echo "========================================="

for i in test/Lexer/in/*.c; do
    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    BASENAME=$(basename $i .c);
    cpp $i test/Lexer/in_preprocessor/$BASENAME.c
    cat test/Lexer/in_preprocessor/$BASENAME.c | bin/c_lexer  > test/Lexer/out/$BASENAME.json  2> test/Lexer/out/$BASENAME.stderr.txt
done
