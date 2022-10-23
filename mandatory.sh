#!/bin/bash

gcc -Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c main.c -o readfile && ./readfile $2
rm -rf readfile
