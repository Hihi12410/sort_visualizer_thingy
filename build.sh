#!/bin/sh
gcc -o $1 sort.c essentials.c $1.c -lSDL2 -g -fsanitize=address -LSAN_OPTIONS=verbosity=1:log_threads=1
