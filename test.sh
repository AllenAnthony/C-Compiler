#!/usr/bin/env bash
mkdir build
cd build
cmake ..
make -j3   #编译
cd ..
./build/compiler $1 $2   #运行，生成中间表示以及汇编代码
dot -Tpng ir_tree.dot -o ir_tree.png   #生成中间表示图片
open ./ir_tree.png  #显示图片
dosbox   #打开DOSBOX
