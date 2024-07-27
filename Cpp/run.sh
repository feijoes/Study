#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <CppFileWithoutExtension>"
    exit 1
fi

FILE_NAME=$1

g++ ${FILE_NAME}.cpp -o ${FILE_NAME}.out

if [ $? -eq 0 ]; then
    printf "Compilation successful. Running the program...\n\n"
    ./${FILE_NAME}.out
    rm -f ${FILE_NAME}.out
    echo "Cleanup: Deleted ${FILE_NAME}.out"
else
    echo "Compilation failed."
    exit 1
fi
