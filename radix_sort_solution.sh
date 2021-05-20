RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"

if [ $# -lt 2 ]
then
	printf "${RED}Error : not enough arguments${NOCOLOR}\n"
	printf "Usage : bash radix_sort_solution.sh <stack numbers>\n"
	printf "Example : bash radix_sort_solution.sh \"9 4 8 7\"\n"
	exit 1
fi

g++ ./files/algo.cpp -o ./files/algo
./files/algo $@
rm -rf ./files/algo