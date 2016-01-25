#!/bin/bash
mkdir -p bin
clang -O3 -DNDEBUG -o bin/$2 "$1/$2.c" && ./bin/$2