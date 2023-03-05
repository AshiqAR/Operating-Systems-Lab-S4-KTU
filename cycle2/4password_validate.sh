#!/bin/bash
echo "strength of password"
read -p "Enter the password : " password
len=${#password}
if [ $len -ge 8 ];
then
	echo "$password" | grep -q [A-Z]
	if [ $? -eq 0 ];
	then
		echo "$password" | grep -q [a-z]
		if [ $? -eq 0 ];
		then
			echo "$password" | grep -q [0-9]
			if [ $? -eq 0 ];
			then
				echo "$password" | grep -q _
				if [ $? -eq 0 ];
				then
					echo "Strong Password"
				else
					echo "Weak password"
				fi
			else
				echo "Weak password"
			fi
		else
			echo "Weak password"
		fi
	else
		echo "Weak password"
	fi
else
	echo "Weak password"
fi
