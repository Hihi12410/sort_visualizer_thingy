#!/bin/sh
gcc -o ./builds/stable$1 ./modules/sort.c ./modules/essentials.c $1.c -lSDL2
./builds/stable/$1
