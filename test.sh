#!/usr/bin/env bash
cd build
cmake ..
make
cd ..
./build/compiler ./testcase/1.txt
dot -Tpng ir_tree.dot -o ir_tree.png
open ./ir_tree.png
