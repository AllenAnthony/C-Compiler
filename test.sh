#!/bin/bash
echo "---- Usage: ./test.sh <filename in ./testcase/ > -----"
make clean
make
./compiler < ./testcase/$1
