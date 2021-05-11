#add leaks test

RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"
TIME_LIMIT=5.0

if [[ "$1" = "clean" ]]
then
	./files/generate_clean_test_cases $2 > ./trace_debug/test_case.txt
else
	./files/generate_random_test_cases $1 > ./trace_debug/test_case.txt
fi

make -C ../

clear

if [[ -f "../push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\n\n"
	exit 1
fi

timeout $TIME_LIMIT ../push_swap $(cat ./trace_debug/test_case.txt) > ./trace_debug/output.txt

time_check=$(echo $?)

if [[ "$time_check" = "124" ]]
then
	printf "${RED}TLE${NOCOLOR}\n"
	exit 1
fi

cat ./trace_debug/output.txt > instructions

./files/checker_bonus $(cat ./trace_debug/test_case.txt)
rm instructions
echo "test_case and output are in trace_debug"
