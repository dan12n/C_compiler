#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
cd ../../
make clean
echo " Force building histogram"
make bin/c_parser
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
    exit;
fi
echo ""
mkdir -p test/Parser/out
mkdir -p test/Parser/in_preprocessor

echo "========================================="

for i in test/Parser/in/*.c; do
    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    BASENAME=$(basename $i .c);
    #cpp $i test/Parser/in_preprocessor/$BASENAME.c
    cat test/Parser/in/$BASENAME.c | bin/c_parser  > test/Parser/out/$BASENAME.xml
    xmllint --noout test/Parser/out/$BASENAME.xml;
    echo $?
done
