echo "Filename Checking"
read -p "Enter the number of filenames to check : " n
echo "Enter the names"
for((i=0;i<n;++i))
do
	read fnm[$i]
done
echo "Checking & conversion.."
for((i=0;i<n;++i))
do
	if [ -e ${fnm[$i]} ]
	then
		a=${fnm[$i]^^}
		echo "${fnm[$i]} - $a - yes"
	else
		echo "${fnm[$i]} - no"
	fi
done
