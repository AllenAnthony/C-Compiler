#!/bin/bash
make clean
make
./compiler < test.c
