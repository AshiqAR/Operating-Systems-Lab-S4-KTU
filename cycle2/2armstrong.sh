#!/bin/bash

echo "Enter the range"
read a b

i=$a

while [ $i -le $b ];
do
	num=$i
	len=0
	while [ $num -ne 0 ];
	do
		len=$(($len+1))
		num=$((num / 10))
	done

	num=$i
	sum=0
	while [ $num -ne 0 ];
	do
		r=$(($num % 10))
		x=1
		v=1
		while [ $x -le $len ]; 
		do
			v=$(($v * $r))
			x=$(($x+1))
		done
		sum=$(($sum+$v))
		num=$(($num/10))
	done

	if [ $sum -eq $i ]
	then
		echo "$i "
	fi

	i=$(($i+1))
done
