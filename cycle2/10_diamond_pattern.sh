read -p "Enter value of n : " n
count=$((n/2+1))
s=$((n%2))
for((i=1;i<$(((n/2)+1+s));++i))
do
	for((j=1;j<$count;++j))
	do
		echo -n " "
	done
	count=$((count-1))
	for((j=1;j<=$(((2*i)-1));++j))
	do
		echo -n "*"
	done
	echo ""
done
count=1
for((i=1;i<=$((n/2));++i))
do
	for((j=1;j<=$count;++j))
	do
		echo -n " "
	done
	count=$((count+1))
	for((j=1;j<=$(((n-(2*i)-s+1)));++j))
	do
		echo -n "*"
	done
	echo ""
done
