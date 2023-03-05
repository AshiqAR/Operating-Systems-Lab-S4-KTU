#!/bin/bash

read -p "Enter the numnber of rows: " n

i=1
while [ $i -le $n ];
do
	j=1
	while [ $j -le $i ]
	do
		echo -n "$i"
		j=$(($j+1))
	done
	echo ""
	i=$(($i+1))
done
