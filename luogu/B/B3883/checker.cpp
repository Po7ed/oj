#include <cstdlib>
#include <cstdio>

int main()
{
	int T;
	puts("T:");
	scanf("%d",&T);
	system("g++ gen.cpp -o gen -O2");
	system("g++ dfs.cpp -o dfs -O2");
	system("g++ force.cpp -o force -O2");
	while(T--)
	{
		system("gen.exe > data.in");
		system("dfs.exe < data.in > dfs.out");
		system("force.exe < data.in > force.out");
		puts("Finding diff...");
		if(system("fc dfs.out force.out"))
		{
			system("pause>nul");
			return 0;
		}
	}
	puts("No Wrongs.");
	return 0;
}