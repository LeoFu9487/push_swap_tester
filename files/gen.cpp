#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>
#include <unordered_set>
#include <ctime>

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(int ac, char **av)
{
    FAST
    vector<int> num;
    int stack_size = 100;
    if (ac > 1) stack_size = atoi(av[1]);
    for(int i = 0 ; i < stack_size ; ++i) num.push_back(i);
    srand(time(0));
    random_shuffle(num.begin(),num.end());
    for(int i = 0 ; i < stack_size ; ++i) cout << num[i] << "\n";
    return 0;
}