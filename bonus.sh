#!/bin/bash

BUFFER=$1

if [ $BUFFER == 1 ]
then
	BUFFER=2;
fi
gcc -Wall -Wextra -Werror -fsanitize=address bonus.c get_*_bonus.c -D BUFFER_SIZE=$BUFFER -o readfile && ./readfile $2 $3 $4 $5
rm -rf readfile
