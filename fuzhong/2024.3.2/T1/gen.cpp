#include <iostream>
#include <random>
#include <ctime>

typedef long long ll;

std::mt19937 random(time(0));
ll tmp;
int get(ll l,ll r) // [l,r]
{
	tmp=r-l+1;
	return (random()%tmp+tmp)%tmp+l;
}

int main()
{
	freopen("string.in","w",stdout);
	puts("30 30");
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			if(get(0,1))
			{
				printf("%c",get('a','z'));
			}
			else
			{
				printf("%c",get('A','Z'));
			}
		}
		puts("");
	}
	return 0;
}