ROOT=..
TIME_LIMIT=2.0




RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"

make bonus -C ./files/

if [[ "$1" = "clean" ]]
then
	g++ -O3 ./files/gen.cpp -o ./files/generate_clean_test_cases
	./files/generate_clean_test_cases $2 > ./trace_debug/test_case.txt
	rm -rf ./files/generate_clean_test_cases
elif [[ "$1" = "random" ]]
then
	g++ -O3 ./files/main.cpp -o ./files/better_random_test_cases
	./files/better_random_test_cases $2 > ./trace_debug/test_case.txt
	rm -rf ./files/better_random_test_cases
else
	echo "$@" > ./trace_debug/test_case.txt
fi

make -C $ROOT/

clear

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in debug.sh is correct\n"
	exit 1
fi

($ROOT/push_swap $(cat ./trace_debug/test_case.txt) > ./trace_debug/output.txt 2>stderr) & pid=$!
(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
if wait $pid 2>/dev/null; then
	TLEFLAG=0
else
	if [[ -s stderr ]]
	then
		printf "${RED}Error${NOCOLOR}\n"
	else
		printf "${RED}TLE${NOCOLOR}\n"
	fi
	rm -rf stderr
	exit 1
fi


cat ./trace_debug/output.txt > instructions
./files/checker_bonus $(cat ./trace_debug/test_case.txt)
rm -rf instructions
echo "test_case and output are in trace_debug"
