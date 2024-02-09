#include <iostream>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d",&T);
	printf("[");
	system("cd /d G:\\zjd\\C++Code\\oj\\luogu\\CF\\CF522D");
	printf("=");
	system("g++ CF522D.cpp -o CF522D -O2 > nul");
	printf("=");
	system("g++ std.cpp -o std -O2 > nul");
	printf("=");
	system("g++ gen.cpp -o gen -O2 > nul");
	printf("=]");
	puts("Start.");
	while(T--)
	{
		printf("No.%d:",T);
		printf("[");
		system("gen > data");
		printf("=");
		system("CF522D < data > my");
		printf("=");
		system("std < data > ans");
		printf("=]");
		if(system("fc my ans"))
		{
			puts("Wrong.");
			system("pause>nul");
			return 0;
		}
	}
	puts("End.");
	return 0;
}