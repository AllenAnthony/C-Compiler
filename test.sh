#!/usr/bin/env bash
cd build
cmake ..
make
cd ..
./build/compiler < ./testcase/1.txt
./build/compiler < ./testcase/2.txt
