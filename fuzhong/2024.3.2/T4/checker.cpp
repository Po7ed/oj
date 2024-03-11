#include <iostream>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d",&T);
	printf("[");
	// system("cd /d G:\\zjd\\C++Code\\myproblems\\T4-extremum");
	// printf("=");
	system("g++ .\\ac.cpp -o ac -O2");
	printf("=");
	system("g++ .\\T4.cpp -o T4 -O2");
	printf("=");
	system("g++ .\\gen.cpp -o gen -O2");
	printf("=]");
	puts("Start.");
	while(T--)
	{
		printf("No.%d:",T);
		printf("[");
		system("gen > .\\tmp.in");
		printf("=");
		system("ac < .\\tmp.in > .\\ac.out");
		printf("=");
		system("T4 < .\\tmp.in > .\\my.out");
		printf("=]");
		if(system("fc .\\ac.out .\\my.out"))
		{
			puts("Wrong.");
			system("pause>nul");
			return 0;
		}
	}
	puts("End.");
	return 0;
}