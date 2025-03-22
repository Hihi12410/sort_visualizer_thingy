#!/bin/sh
gcc -o $PWD/builds/stable/$1 $PWD/modules/sort.c $PWD/modules/essentials.c $1.c -lSDL2 -g -fsanitize=address -LSAN_OPTIONS=verbosity=1:log_threads=1
$PWD/builds/stable/$1
