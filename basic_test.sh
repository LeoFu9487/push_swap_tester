ROOT=..
TRACE=./trace_basic

RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

make -C $ROOT

clear

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\n\n"
	exit 1
fi

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

printf "_____________ERROR_______________TEST_____________\n\n"

for ((i=1;i<=15;i++));
do
	printf "test_case_$i\n"
	$ROOT/push_swap $(cat $TRACE/error_files/test_case_$i.txt) >stdout 2>stderr
	if [[ -s stdout ]];
	then
		printf "${RED}KO, stdout must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		printf "${GREEN}OK${NOCOLOR}\n"
	fi
	if [[ -s stderr ]];
	then
		printf "Error\n" > e
		diff e stderr > x
		if [[ -s x ]]
		then
			printf "${RED}KO, Output message in stderr is wrong\n${NOCOLOR}"
		else
			printf "${GREEN}OK${NOCOLOR}\n"
		fi
		rm -rf e x
	else
		printf "${RED}KO, \"Error\" must be written in stderr followed by a newline${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	fi
	rm -rf stdout stderr
done



printf "ERROR_TEST result : $FLAG\n"

#TLE, LEAKS, check ROOT