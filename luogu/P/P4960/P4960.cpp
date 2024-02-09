#include <iostream>
#include <map>
using namespace std;

constexpr int N=1145;
int n,a[N];
map<int,int> cnt;

int main()
{
	scanf("%d",&n);
	int dif=0,mac=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(!cnt.count(a[i]))dif++;
		mac=max(mac,++cnt[a[i]]);
	}
	if(mac<dif)// type 2
	{
		printf("%d 2\n",mac);
		int siz;
		while(true)
		{
			siz=0;
			for(pair<int,int> p:cnt)if(p.second)siz++;
			if(!siz)break;
			printf("%d",siz);
			for(pair<int,int> p:cnt)if(p.second)
				printf(" %d",p.first),cnt[p.first]--;
			puts("");
		}
	}
	else
	{
		printf("%d 1\n",dif);
		for(pair<int,int> p:cnt)
		{
			printf("%d",p.second);
			while(p.second--)printf(" %d",p.first);
			puts("");
		}
	}
	return 0;
}