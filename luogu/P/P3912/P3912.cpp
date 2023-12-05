#include <iostream>
#include <bitset>
using namespace std;

int prime[6191981],cnt=0;
bitset<size_t(1e8+8)> is;

int main()
{
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	prime[cnt++]=2;
	for(int i=3;i<=n;i++)
	{
		if((i&1)&&!is[i])
		{
			prime[cnt++]=i;
			for(int j=2;i*j<=n;j++)
			{
				is[i*j]=true;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}