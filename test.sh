#!/bin/bash
make clean
make
echo "---- format: ./test.sh <filename in ./testcase> -----"
./compiler < testcase/$1
