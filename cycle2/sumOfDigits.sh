read -p "Enter the number: " a;
sum=0;

for((i=a;i!=0;i=i/10))
do
    dig=$(($i%10));
    echo "$dig";
    sum=$(($sum+$dig));
done
echo "$sum";