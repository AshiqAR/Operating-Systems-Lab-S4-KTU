read -p "Enter the value of n: " n;

a=0;
b=1;

for((i=3;i<=n;i++))
do
    c=$(($a+$b));
    a=$b;
    b=$c;
done

if((n==1))
then
    c=0;
elif((n==2))
then
    c=1;
fi

echo "$c";