#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=11451419;
int n,q;
int nxt[N],lst;
bitset<N> isn;// 不能选

inline void init()
{
	for(int i=1;i<=N;i++)
	{
		if(!isn[i])
		{
			if(i%7==0||to_string(i).find('7')!=string::npos)
			{
				for(int t=1;i*t<=N;t++)
				{
					isn[i*t]=true;
				}
			}
			if(!isn[i])
			{
				nxt[lst]=i;
				lst=i;
			}
		}
	}
}

int main()
{
	init();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		if(isn[n])
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",nxt[n]);
		}
	}
	return 0;
}