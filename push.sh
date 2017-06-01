#!/bin/bash

rm -rf lex.yy.* *.tab.cpp *.tab.hpp *.tab.c *.tab.h *.output *.o
git add .
if $1
then
    git commit -m "auto commit"
else
    git commit -m "$1"
fi
git push

