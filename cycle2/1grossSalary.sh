#!/bin/bash

echo "Enter the basic salary"
read b

if [ $b -lt 1500 ]
then
	hra=$(($b * 10/100))
	da=$(($b * 90/100))
else
	hra=$((500))
	da=$(($b * 98 / 100))
fi

sum=$(($b + $hra + $da))
echo "Final salary = $sum"
