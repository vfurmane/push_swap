#!/bin/bash

[ -n "$1" ] && number_of_elms=$1 || number_of_elms=10

ARG=$(shuf -z -i 1-$number_of_elms -n $number_of_elms | tr '\0' ' ')

i=0
while true
do
	i=$(($i + 1))
	printf "\r%d" $i
	result=$(./push_swap $ARG)
	if grep -Pz "^pb\npa" <(echo "$result") > /dev/null 2>&1 ||
		grep -Pz "^pa\npb" <(echo "$result") > /dev/null 2>&1 ||
		grep -Pz "^ra\nrra" <(echo "$result") > /dev/null 2>&1 ||
		grep -Pz "^rra\nra" <(echo "$result") > /dev/null 2>&1
	then
		echo
		echo -e "$result"
		echo "Arg below:"
		echo $ARG
		exit 1
	fi
done
