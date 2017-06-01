cmake_minimum_required(VERSION 3.7)
project(compiler)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-g")

#FLEX BISON设置
find_package(BISON)
find_package(FLEX)
BISON_TARGET(Parser c.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.cpp)
FLEX_TARGET(Scanner c.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

#设置关联文件夹，关联当前文件夹和生成目标文件夹的文件
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})


#工具Utils
set(UTILS util.cpp)

set(ASB_TREE abs.cpp)

set(SEMANT semant.cpp symbol.cpp function.cpp)

#编译生成compiler
set(SOURCE_FILES ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS} ${UTILS} ${ASB_TREE} ${SEMANT})
add_executable(compiler ${SOURCE_FILES})