# push_swap_tester

### Usage :

First, go to the root of your repository, which is where we can find your Makefile

```git clone https://github.com/LeoFu9487/push_swap_tester.git```

```cd push_swap_tester```

Then there are two modes of test :

###### 1. loop mode

```bash loop.sh <stack size> <loop times>```

result of the following command

```bash loop.sh 100 10```

![example](https://user-images.githubusercontent.com/70040774/118051305-0b7fa580-b381-11eb-9568-36b44748b10f.png)


###### 2. visualization mode (debug mode)

generate and visualize random numbers : 

```bash debug.sh <stack size>```

result of the following command

```bash debug.sh 10```

![example2](https://user-images.githubusercontent.com/70040774/118052309-cceaea80-b382-11eb-8c9d-39675e9143ba.png)

or

generate and visualize numbers from 0 to n - 1

```bash debug.sh clean <stack size>```

result of the following command

```bash debug.sh clean 10```

![example3](https://user-images.githubusercontent.com/70040774/118052350-daa07000-b382-11eb-95e4-c8715f70cc05.png)

### Result 

OK : answer correct

KO : Wrong answer

TLE : time limit exceeded (You can edit the variable ```TIME_LIMIT``` in *.sh file)

ERROR : Unknown instructions

Valgrind not found : We can't test your memory leaks with command leaks

### Clean

```bash clean.sh```

can remove every test case and output file

Contact : 

yfu@student.42lyon.fr

Or you can also DM me on the slack

