#!/bin/bash
echo "Sorting"
read -p "Enter the size of array : " n
echo "Enter the elements"

for (( i = 0; i < n; ++i ))
do
 	read a[$i];
done

for (( i = 0; i < $n; i++ ))
do
 	for(( j = 0; j < $((n-i-1)); ++j ))
 	do
    	if [ ${a[$j]} -gt ${a[$((j+1))]} ];
    	then
      		t=${a[$j]}
      		a[$j]=${a[$((j+1))]}
      		a[$((j+1))]=$t
		fi
 	done
done

echo "Sorted array"
for((i=0;i<n;++i))
do
	echo -n "${a[$i]} "
done
echo " "  
