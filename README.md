# C-Compiler
环境要求：
- bison
- flex
- cmake（跨平台编译）
- graphivz(生成中间代码表示图片)


使用方法：
1. Mac/Linux
- 自动测试：打开终端，进入代码文件夹，运行./test.sh
   自动编译lex yacc等文件，然后使用./testcase/1.txt进行测试，并生成中间树代码

- 编译(在当前文件夹下的build文件夹生成程序)
    mkdir build
    cd build
    cmake ..
    make
    cd ..

- 测试(测试testcase下的1.txt)
    ./build/compiler ./testcase/1.txt

- 生成中间表示（图片保存为ir_tree.png）
    dot -Tpng ir_tree.dot -o ir_tree.png


2. Windows
使用VS或Clion根据Cmakelists.txt生成工程， 编译生成compiler.exe程序
运行compiler.exe <文件名>
生成ir_tree.dot文件
使用graphivz将.dot文件转换成图片

