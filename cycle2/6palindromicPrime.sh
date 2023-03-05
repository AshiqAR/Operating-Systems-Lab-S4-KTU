#!/bin/bash

echo -n "Enter n: "
read n

i=$((n+1))

f=1

while [ $f -eq 1 ]
do
	prime=1
	palindrome=1

	a=$i
	j=2
	while [ $j -lt $a ]
	do
		if [ $((a%j)) -eq 0 ]
		then
			prime=0
		fi
		j=$((j+1))
	done

	rev=0
	while [ $a -ne 0 ]
	do
		rev=$(($rev*10+$a%10))
		a=$(($a/10))
	done

	if [ $i -ne $rev ]
	then
		palindrome=0
	fi

	if [ $prime -eq 1 ] && [ $palindrome -eq 1 ]
	then
		f=0
	fi

	i=$((i+1))
done

i=$((i-1))
echo "number = $i"
