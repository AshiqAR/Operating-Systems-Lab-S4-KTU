#!/bin/bash
echo "Linear Search"
read -p "Enter the size of array : " n
echo "Enter the elements"

for (( i = 0; i < n; ++i ))
do
 	read a[$i]
done

echo -n "Enter the key : "
read k

for (( i = 0; i < n; i++ ))
do
	if [ ${a[$i]} -eq $k ]
	then
		break
	fi
done

if [ $i -eq $n ]
then
	echo "element not found"
else
	echo "found at index $i"
fi
