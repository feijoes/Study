#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <PascalFileWithoutExtension>"
    exit 1
fi

FILE_NAME=$1

fpc ${FILE_NAME}.pas

if [ $? -eq 0 ]; then
    printf "Compilation successful. Running the program...\n\n"
    sudo ./${FILE_NAME}
    rm -f ${FILE_NAME}.o ${FILE_NAME}
    echo "Cleanup: Deleted ${FILE_NAME}.o and ${FILE_NAME}."
else
    echo "Compilation failed."
    exit 1
fi
