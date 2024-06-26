#!/bin/bash
gcc -o out/${1%.*} $1
./out/${1%.*}