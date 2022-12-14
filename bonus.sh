#!/bin/bash

if [ -z "$1" ]
then
	echo Empty buffer size.;
	echo Run: bash bonus.c [BUFFER_SIZE] [FILES...];
else
	BUFFER=$1
	
	if [ $BUFFER == 1 ]
	then
		BUFFER=2;
	fi
	gcc -Wall -Wextra -Werror -fsanitize=address bonus.c get_*_bonus.c -D BUFFER_SIZE=$BUFFER -o readfile && ./readfile $2 $3 $4 $5
	rm -rf readfile
fi
