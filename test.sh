#add multiple tests
#add bonus
#add leaks test


RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"
TIME_LIMIT=5.0

./files/generate_random_test_cases $@ > ./trace/test_case.txt

make -C ../

clear

if [[ -f "../push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\n\n"
	exit 1
fi

timeout $TIME_LIMIT ../push_swap $(cat ./trace/test_case.txt) > ./trace/output.txt

time_check=$(echo $?)

printf "stack size		"
cat ./trace/test_case.txt | wc -l
printf "instructions amounts	"
cat ./trace/output.txt | wc -l
printf "checker result		"
if [[ "$time_check" = "124" ]]
then
	printf "${RED}TLE${NOCOLOR}\n"
	exit 1
fi
cat ./trace/output.txt | ./files/checker $(cat ./trace/test_case.txt) > temp_result
temp=$(cat temp_result)
if [[ "$temp" = "OK" ]]
then
	printf "${GREEN}OK${NOCOLOR}\n"
elif [[ "$temp" = "KO" ]]
then
	printf "${RED}KO${NOCOLOR}\n"
else
	printf "${RED}ERROR${NOCOLOR}\n"
fi
rm -rf temp_result
printf "\n\n"
echo "test_case and output is in trace"
