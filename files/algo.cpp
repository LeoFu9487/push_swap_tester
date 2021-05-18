#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <cstdio>

#define top back
#define push_top push_back
#define pop_top pop_back
#define bottom front
#define push_bottom push_front
#define pop_bottom pop_front

using namespace std;

deque<int> a,b;
int max_bits = 4;

string convert_base_2(int n)
{
	string ans;
	for(int i = max_bits - 1 ; i >= 0 ; --i){
		if ((n>>i)&1) ans += "1";
		else ans += "0";
	}
	return ans;
}

void print_stacks_base2()
{
	int x = a.size(), y = b.size();
    deque<int>::reverse_iterator i = a.rbegin(), j = b.rbegin();
	while (x > y)
	{
		printf("%10s%15s\n", convert_base_2(*i).c_str(), "");
		--x;
		++i;
	}
	while (y > x)
	{
		printf("%15s%10s\n", "", convert_base_2(*j).c_str());
		--y;
		++j;
	}
	while (x--)
	{
		printf("%10s%5s%10s\n", convert_base_2(*i).c_str(), "", convert_base_2(*j).c_str());
		++i;
		++j;
	}
	for(int i = 0 ; i < 10 ; ++i) printf("-");
	printf("%5s","");
	for(int i = 0 ; i < 10 ; ++i) printf("-");
	printf("\n");
	printf("%10s%5s%10s\n\n", "a", "", "b");
}

void print_stacks()
{
	int x = a.size(), y = b.size();
	deque<int>::reverse_iterator i = a.rbegin(), j = b.rbegin();
	while (x > y)
	{
		printf("%10d%15s\n", *i, "");
		--x;
		++i;
	}
	while (y > x)
	{
		printf("%15s%10d\n", "", *j);
		--y;
		++j;
	}
	while (x--)
	{
		printf("%10d%5s%10d", *i, "", *j);
		++i;
		++j;
	}
	for(int i = 0 ; i < 10 ; ++i) printf("-");
	printf("%5s","");
	for(int i = 0 ; i < 10 ; ++i) printf("-");
	printf("\n");
	printf("%10s%5s%10s\n\n", "a", "", "b");
}

void pa()
{
	#ifdef REAL
	printf("pa\n");
	if (b.empty()) return ;
	a.push_top(b.top());
	b.pop_top();
	return ;
	#endif
	//printf("\npa\n");
	if (b.empty()) return ;
	a.push_top(b.top());
	b.pop_top();
	//print_stacks_base2();
}

void pb()
{
	#ifdef REAL
	printf("pb\n");
	if (a.empty()) return ;
	b.push_top(a.top());
	a.pop_top();
	return ;
	#endif
	//printf("\npb\n");
	if (a.empty()) return ;
	b.push_top(a.top());
	a.pop_top();
	//print_stacks_base2();
}

void ra()
{
	#ifdef REAL
	printf("ra\n");
	if (a.empty()) return ;
	a.push_bottom(a.top());
	a.pop_top();
	return ;
	#endif
	//printf("\nra\n");
	if (a.empty()) return ;
	a.push_bottom(a.top());
	a.pop_top();
	//print_stacks_base2();
}

void clearscreen()
{
    printf("\e[1;1H\e[2J");
}


int main(int ac, char **av)
{
	vector<int> array;
    for (int i = 1 ; i < ac ; ++i)
    {
        array.push_back(atoi(av[i]));
    }
    if (ac < 2) return 0;

//step 1 : simplify numbers
    

	vector<int> copy_array(array), copy(array);
	sort(copy_array.begin(), copy_array.end());

	{
		unordered_map<int,int> hash;
		for(int i = 0 ; i < copy_array.size() ; ++i)
		{
			hash[copy_array[i]] = i;
		}
		for(int i = 0 ; i < array.size() ; ++i)
		{
			array[i] = hash[array[i]];
		}
	}
	//put the simplified numbers into a
	for(int i = 0 ; i < array.size() ; ++i)
	{
		a.push_bottom(array[i]);
	}
//step 1 done

    clearscreen();
    printf("\nstep 1 : simplify numbers\n\n");

    for(int i = 0 ; i < array.size() ; ++i)
    {
        printf("%d\t->\t%d\n", copy[i], array[i]);
    }

    printf("\n\nOriginal input : ");
    for(int i = 0 ; i < array.size() ; ++i) printf("%d ", copy[i]);
    printf("\n\nSimplified arr : ");
    for(int i = 0 ; i < array.size() ; ++i) printf("%d ", array[i]);
    printf("\n\npress enter to continue ...");
    while (getchar() != '\n')
    {
        
    }

//step 2 : algorithms
	
	max_bits = 0;
	while ((array.size()-1)>>max_bits) ++max_bits;
    clearscreen();
	printf("\nstep 2 : put numbers in stack and visualize it in base 2\n\n");
    printf("arr : ");
    for(int i = 0 ; i < array.size() ; ++i) printf("%d ", array[i]);
    printf("\n\n");
    for(int i = 0; i < array.size() ; ++i)
    {
        printf("%d\t->\t%s\n", array[i], convert_base_2(array[i]).c_str());
    }
         printf("\n");
    print_stacks_base2();
    printf("\npress enter to continue ...");
    while (getchar() != '\n')
    {
        
    }
    clearscreen();
    printf("\nALGO TIME !\n\n1) normal mode\n2) step by step mode\n\nPlease enter 1 or 2\n");
    char n;
    while ( cin >> n )
    {
        if (n == '1')
        {
            printf("\nnormal mode !\n");
            break ;
        }
        if (n == '2')
        {
            printf("\nstep by step mode !\n");
            break ;
        }
        printf("invalid input ! please type 1 or 2\n");
    }
    printf("\npress enter to continue ...");
    while (getchar() != '\n')
    {

    }

    if (n == '1')
    {
        
        for (int i = 0 ; i < max_bits ; ++i)
        {
            clearscreen();
            printf("original status :\n\n");
            print_stacks_base2();
            for(int j = 0 ; j < array.size() ; ++j)
            {
                if ((a.top()>>i)&1) ra();
                else pb();
            }
            printf("seperate into two boxes for the %d-th time ( check the %d-th digit from the right )\n\n", i + 1, i + 1);
            print_stacks_base2();
            printf("\npress enter to continue ...");
            while (getchar() != '\n'){}
            clearscreen();
            printf("original status :\n\n");
            print_stacks_base2();
            while (b.size()) pa();
            printf("put all back in stack a\n\n");
            print_stacks_base2();
            if (i == max_bits - 1) printf("sorted !\n");
            printf("\npress enter to continue ...");
            while (getchar() != '\n'){}
        }
    }

    else
    {
        for(int i = 0 ; i < max_bits ; ++i)
        {
            for(int j = 0 ; j < array.size() ; ++j)
            {
                clearscreen();
                printf("original status :\n\n");
                print_stacks_base2();
                if ((a.top()>>i)&1)
                {
                    ra();
                    printf("ra\n\n");
                    print_stacks_base2();
                }
                else
                {
                    pb();
                    printf("pb\n\n");
                    print_stacks_base2();
                }
                printf("\npress enter to continue ...");
                while (getchar() != '\n'){}
            }
            while (b.size())
            {
                clearscreen();
                printf("original status :\n\n");
                print_stacks_base2();
                pa();
                printf("pa\n\n");
                print_stacks_base2();
                printf("\npress enter to continue ...");
                while (getchar() != '\n'){}
            }
        }
    }
//step 2 done
}