#!/bin/bash

betty *.c
betty *.h

if [ $? -ne 0 ]; then
	echo -e "\nBad Coding Style."
	exit
fi

gcc -o monty *.c -Wall -Wextra -Werror -pedantic -std=gnu89
