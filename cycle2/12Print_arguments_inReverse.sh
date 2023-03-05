echo "Reverse Command Arguments"
echo "Total number of arguments : $#"
echo "Arguments : $@"
echo "In reverse order"
n=$#
args=("$@")
for((i=$((n-1));i>=0;--i))
do
  echo -n "${args[${i}]}   "
done
echo " "
