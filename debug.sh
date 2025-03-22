#!/bin/sh
gcc -o ./builds/stable$1 ./modules/sort.c ./modules/essentials.c $1.c -lSDL2 -g -fsanitize=address -LSAN_OPTIONS=verbosity=1:log_threads=1
./builds/stable/$1
