#!/bin/sh
gcc -o $PWD/builds/stable/$1 $PWD/modules/sort.c $PWD/modules/essentials.c $1.c -lSDL2
$PWD/builds/stable/$1
