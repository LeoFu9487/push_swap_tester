#add leaks test

RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"
TIME_LIMIT=1.0

for ((i=1;i<=$2;i++));
do
./files/better_random_test_cases $@ > ./trace_loop/test_case_$i.txt
done

make -C ../

clear


if [[ -f "../push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\n\n"
	exit 1
fi

declare -i total=0
declare -i count=0
declare -i max=0
declare -i min=1000000000
FLAG="${GREEN}OK${NOCOLOR}"
for ((i=1;i<=$2;i++));
do
printf "$i		"
timeout $TIME_LIMIT ../push_swap $(cat ./trace_loop/test_case_$i.txt) > ./trace_loop/output_$i.txt
time_check=$(echo $?)
printf "instructions amounts : "
count=$(cat ./trace_loop/output_$i.txt | wc -l)
printf "$count "
total=$((total + count))
if [ $count -gt $max ]
then
	max=count
	max_tag=$i
fi
if [ $count -lt $min ]
then
	min=count
	min_tag=$i
fi
printf "	checker result : "
if [[ "$time_check" = "124" ]]
then
	printf "${RED}TLE${NOCOLOR}\n"
	FLAG="${RED}KO${NOCOLOR}"
else
cat ./trace_loop/output_$i.txt | ./files/checker $(cat ./trace_loop/test_case_$i.txt) > temp_result
temp=$(cat temp_result)
if [[ "$temp" = "OK" ]]
then
	printf "${GREEN}OK${NOCOLOR}\n"
elif [[ "$temp" = "KO" ]]
then
	printf "${RED}KO${NOCOLOR}\n"
	FLAG="${RED}KO${NOCOLOR}"
fi
fi
done
rm -rf temp_result
average=$((total/$2))
printf "\n"
printf "stack size 		$1\n"
printf "loop time		$2\n"
printf "test result		$FLAG\n"
printf "total instructions	$total\n"
printf "maximum instructions	$max (test case $max_tag)\n"
printf "minimum instructions	$min (test case $min_tag)\n"
printf "average instructions	$average\n"
echo "test_case and output are in trace_loop"