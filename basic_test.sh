ROOT=..
TIME_LIMIT=1





TRACE=./trace_basic
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

make -C $ROOT

clear

confirm() {
    # call with a prompt string or use a default
    read -r -p "${1:-Continue? [y/N]} " response
    case "$response" in
        [yY][eE][sS]|[yY]) 
            clear
            ;;
        *)
			printf "EXIT\n"
            exit 0
            ;;
    esac
}

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in basic_test.sh is correct\n"
	exit 1
fi

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

printf "_____________ERROR_______________TEST_____________\n\n"

for ((i=1;i<=15;i++));
do
	printf "test_case_$i\n\n"
	printf "one number per argument : \n\n"
	($ROOT/push_swap $(cat $TRACE/error_files/test_case_$i.txt) > stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
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
	rm -rf stdout stderr a b
	(leaks -atExit -- $ROOT/push_swap $(cat $TRACE/error_files/test_case_$i.txt) 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n"
	rm -rf a b x y
	printf "\none argument\n\n"
	($ROOT/push_swap "$(cat $TRACE/error_files/test_case_$i.txt)" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
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
	(leaks -atExit -- $ROOT/push_swap "$(cat $TRACE/error_files/test_case_$i.txt)" 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf a b x y
done

printf "test_case_16\n\n"
	($ROOT/push_swap "123 1 2" "654 456 123" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
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
	(leaks -atExit -- $ROOT/push_swap "123 1 2" "654 456 123" 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf a b x y

printf "\n\nERROR_TEST\n\nresult : $FLAG\nmemory : $LEAKFLAG\n\n\n"

confirm

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

printf "__________IDENTITY_______________TEST_____________\n\n"

for ((i=1;i<=9;i++));
do
	printf "test_case_$i\n\n"
	($ROOT/push_swap "$(cat $TRACE/identity_files/test_case_$i.txt)" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	if wait $pid 2>/dev/null; then
		TLEFLAG=0
	else
		TLEFLAG=1
	fi
	if [[ "$TLEFLAG" = "1" ]]
	then
		printf "${RED}TLE${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	elif [[ -s stdout ]];
	then
		printf "${RED}KO, stdout and stderr must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	elif [[ -s stderr ]];
	then
		printf "${RED}KO, stdout and stderr must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		printf "${GREEN}OK${NOCOLOR}\n"
	fi
	rm -rf stderr stdout
	(leaks -atExit -- $ROOT/push_swap "$(cat $TRACE/identity_files/test_case_$i.txt)" 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf a b x y
done

	printf "IDENTITY_TEST\n\nresult : $FLAG\nmemory : $LEAKFLAG\n\n\n"

	confirm

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

make -C ./files/

clear

printf "________SMALL_______STACK_______TEST________\n\n"

printf "SIZE 3 (sort with not more than 3 operations) : \n\n"

for i in {1..5}
do
	printf "test_case_$i\n\n"
	($ROOT/push_swap "$(cat $TRACE/size3/test_case_$i.txt)" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	if wait $pid 2>/dev/null; then
		TLEFLAG=0
	else
		TLEFLAG=1
	fi
	if [[ -s stderr ]];
	then
		printf "${RED}KO, stderr must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		./files/checker "$(cat $TRACE/size3/test_case_$i.txt)" < stdout 1> result 2>error_result
		echo "OK" > ok
		if [[ -s error_result ]];
		then
			printf "${RED}Error${NOCOLOR}\n\n"
			FLAG="${RED}KO${NOCOLOR}"
		else
			diff ok result > aa
			if [[ -s aa ]];
			then
				if [[ "$TLEFLAG" = "1" ]]
				then
					printf "${RED}TLE${NOCOLOR}\n\n"
				else
					printf "${RED}KO, not sorted${NOCOLOR}\n\n"
				fi
				FLAG="${RED}KO${NOCOLOR}"
			else
				amount=$(wc -l < stdout)
				if [[ $amount -gt 3 ]]
				then
					printf "${RED}KO, $amount operations are not acceptable${NOCOLOR}\n\n"
					FLAG="${RED}KO${NOCOLOR}"
				else
					printf "${GREEN}OK, sorted with $amount operations${NOCOLOR}\n\n"
				fi
			fi
		fi
	fi
	rm -rf stdout stderr result error_result ok aa
	(leaks -atExit -- $ROOT/push_swap "$(cat $TRACE/size3/test_case_$i.txt)" 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf a b x y
done

printf "SIZE_3_TEST\n\nresult : $FLAG\nmemory : $LEAKFLAG\n\n\n"

confirm

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"

clear

printf "________SMALL_______STACK_______TEST________\n\n"

printf "SIZE 5 (sort with not more than 12 operations) : \n\n"

for i in {1..119}
do
	printf "test_case_$i\n\n"
	($ROOT/push_swap "$(cat $TRACE/size5/test_case_$i.txt)" >stdout 2>stderr) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	if wait $pid 2>/dev/null; then
		TLEFLAG=0
	else
		TLEFLAG=1
	fi
	if [[ -s stderr ]];
	then
		printf "${RED}KO, stderr must be empty${NOCOLOR}\n"
		FLAG="${RED}KO${NOCOLOR}"
	else
		./files/checker "$(cat $TRACE/size5/test_case_$i.txt)" < stdout 1> result 2>error_result
		echo "OK" > ok
		if [[ -s error_result ]];
		then
			printf "${RED}Error${NOCOLOR}\n\n"
			FLAG="${RED}KO${NOCOLOR}"
		else
			diff ok result > aa
			if [[ -s aa ]];
			then
				if [[ "$TLEFLAG" = "0" ]];
				then
					printf "${RED}KO, not sorted${NOCOLOR}\n\n"
				else
					printf "${RED}TLE${NOCOLOR}\n\n"
				fi
				FLAG="${RED}KO${NOCOLOR}"
			else
				amount=$(wc -l < stdout)
				if [[ $amount -gt 12 ]]
				then
					printf "${RED}KO, $amount operations are not acceptable${NOCOLOR}\n\n"
					FLAG="${RED}KO${NOCOLOR}"
				else
					printf "${GREEN}OK, sorted with $amount operations${NOCOLOR}\n\n"
				fi
			fi
		fi
	fi
	rm -rf stdout stderr result error_result ok aa
	(leaks -atExit -- $ROOT/push_swap "$(cat $TRACE/size5/test_case_$i.txt)" 1>a 2>b) & pid=$!
	(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
	wait $pid 2>/dev/null;
	grep ": 0 leaks for 0 total leaked bytes" a > x
	grep "not found" b > y
	if [[ -s x ]];
	then
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	else
		if [[ -s y ]];
		then
			TEMPLEAK="leaks command not found"
			LEAKFLAG="leaks command not found"
		else
			TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
			LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
		fi
	fi
	printf "$TEMPLEAK\n\n"
	rm -rf a b x y
done

printf "SIZE_5_TEST\n\nresult : $FLAG\nmemory : $LEAKFLAG\n\n\n"
