#!/bin/bash

echo "Enter three numbers : "

read a b c

if [ $a -lt $b ]
then
	if [ $a -lt $c ]
	then
		small=$a
	else
		small=$c
	fi
else
	if [ $b -lt $c ]
	then
		small=$b
	else
		small=$c
	fi
fi

echo "smallest number = $small"
