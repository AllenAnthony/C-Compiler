#!/bin/bash

make clean
git add .
if $1
then
    git commit -m "auto commit"
else
    git commit -m $1
fi
git push

