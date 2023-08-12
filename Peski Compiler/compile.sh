#!/bin/bash
make clean
make
./peski -compile $1 > error_report.txt
./peski -execute $1 > translated_code.c
clang translated_code.c -o peski_executable
clear
./peski_executable
