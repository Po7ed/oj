#include <iostream>
#include <random>
#include <ctime>

constexpr int N=100000,M=100000;

int main()
{
	std::mt19937 rd(time(0));
	printf("%d %d\n",N,M);
	for(int i=1;i<=N;i++)
	{
		printf("%d ",rd()%(N>>2));
	}
	puts("");
	for(int i=1,l,r;i<=M;i++)
	{
		l=rd()%N+1,r=rd()%N+1;
		if(l>r)std::swap(l,r);
		printf("%d %d\n",l,r);
	}
	return 0;
}