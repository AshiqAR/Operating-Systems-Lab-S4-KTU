echo "Three digit numbers with 0,1,2,3"
for (( i = 1; i <= 3; i++ ))
do
	for (( j = 0; j <= 3; j++ ))
	do
		for (( k = 0; k <= 3; k++))
		do
			echo "$i$j$k"
		done
	done
done
