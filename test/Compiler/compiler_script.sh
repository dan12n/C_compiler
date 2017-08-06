#!/bin/bash

echo "========================================"
echo " Cleaning the temporaries and outputs"
cd ../../
make clean
echo " Force building histogram"
make bin/c_compiler
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
    exit;
fi
echo ""
mkdir -p test/Compiler/out
mkdir -p test/Compiler/ref



PASSED=0
CHECKED=0

for i in test/Compiler/in/*; do

	b=$(basename ${i});

	mkdir -p test/Compiler/out/pretty_print/$b
	mkdir -p test/Compiler/ref/bin/$b
	mkdir -p test/Compiler/out/bin/$b
	mkdir -p test/Compiler/ref/assembly/$b
	mkdir -p test/Compiler/out/assembly/$b
	mkdir -p test/Compiler/ref/result/$b
	mkdir -p test/Compiler/out/result/$b

	echo "========================================="
	echo ""
	echo "Testing $b"

    for n in test/Compiler/in/$b/*.c; do

    	echo "==========================="
    	echo ""
    	echo "Input file : ${n}"

	    BASENAME=$(basename $n .c);

	    cat test/Compiler/in/$b/$BASENAME.c | bin/c_compiler  > test/Compiler/out/assembly/$b/$BASENAME.s  2> test/Compiler/out/pretty_print/$b/$BASENAME.stderr.txt
	    #Generates assembly files first for debugging purposes
	    mips-linux-gnu-gcc -c -S test/Compiler/in/$b/$BASENAME.c -o test/Compiler/ref/assembly/$b/$BASENAME.s

	    #Generate executables
	    mips-linux-gnu-gcc -static test/Compiler/ref/assembly/$b/$BASENAME.s -o test/Compiler/ref/bin/$b/$BASENAME
	    mips-linux-gnu-gcc -static test/Compiler/out/assembly/$b/$BASENAME.s -o test/Compiler/out/bin/$b/$BASENAME

	    #Run executables and compare them
	    test/Compiler/ref/bin/$b/$BASENAME
	    GOT_RESULT_REF=$?;
	    echo "${GOT_RESULT_REF}" > test/Compiler/ref/result/$b/$BASENAME.txt
	    
	    test/Compiler/out/bin/$b/$BASENAME
	    GOT_RESULT_OUT=$?;
	    echo "${GOT_RESULT_OUT}" > test/Compiler/out/result/$b/$BASENAME.txt

    	OK=0;

	    #Calculate result
	    if [[("${GOT_RESULT_OUT}" -ne "${GOT_RESULT_REF}") &&  ("${GOT_RESULT_REF}" -ne 127)]]; then
	        echo "  got output : ${GOT_RESULT_OUT}"
	        echo "  ref output : ${GOT_RESULT_REF}"
	        echo "  FAIL!";
	        OK=1;
	    fi

	    if [[ "$OK" -eq "0" ]]; then
	        PASSED=$(( ${PASSED}+1 ));
	    fi

	    CHECKED=$(( ${CHECKED}+1 ));

	    echo ""

	done
done

echo ""
echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""

RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 16.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi