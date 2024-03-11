#include <iostream>
#include <random>
#include <ctime>

typedef long long ll;
constexpr int N=5,M=10;

std::mt19937 random(time(0));
ll tmp;
int get(ll l,ll r) // [l,r]
{
	tmp=r-l+1;
	return (random()%tmp+tmp)%tmp+l;
}

int main()
{
	printf("%d %d\n",N,M);
	for(int i=1,j;i<=N;i++)
	{
		do j=get(1,N);while(i==j);
		printf("%d ",j);
	}
	return 0;
}