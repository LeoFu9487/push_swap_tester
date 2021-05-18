#include <iostream>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>
#include <unordered_set>
#include <unordered_map>

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(int ac, char **av)
{
    FAST
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    vector<int> arr;
    std::mt19937 gen(seed);
    int stack_size = 100;
    if (ac > 1) stack_size = atoi(av[1]);
    unordered_set<int> used;
    for( int j = 0; j < stack_size; ++j )
   {
        int n = static_cast<int>(gen());
        while (used.find(n) != used.end()) n = static_cast<int>(gen());
        used.insert(n);
        arr.push_back(n);
    }

    vector<int> copy = arr;
    sort(copy.begin(),copy.end());
    unordered_map<int,int> mp;
    for(int i = 0 ; i < copy.size() ; ++i) mp[copy[i]] = i;
    for(int i = 0 ; i < arr.size() ; ++i) cout << mp[arr[i]] <<"\n";
    return 0;
}