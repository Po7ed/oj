#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

typedef long long ll;
const int AI=1145,N=114514;
int gcd[AI][AI],a[N],cnt[AI];
vector<int> b;

inline void init()
{
	for(int i=0;i<AI;i++)
	{
		gcd[0][i]=gcd[i][0]=i;
	}
	// printf("(2,0)=%d\n",gcd[2][0]);
	for(int i=1;i<AI;i++)
	{
		for(int j=1;j<AI;j++)
		{
			// if(i==2&&j==0)
			// {
			// 	printf("SB");
			// }
			if(i>=j)
			{
				gcd[j][i]=gcd[i][j]=gcd[j][i%j];
				// printf("gcd(%d,%d)=%d (%d,%d)\n",i,j,gcd[i][j],j,i%j);
			}
		}
	}
}

int main()
{
	// freopen("gcd.in","r",stdin);
	// freopen("gcd.out","w",stdout);
	time_t beg=clock();
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	b.push_back(-1);
	for(int i=1;i<=n;i++)
	{
		if(b.back()!=a[i])
		{
			b.push_back(a[i]);
		}
		cnt[a[i]]++;
	}
	// puts("End of Unique.");
	int m=b.size()-1;
	// printf("%d",m);
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ans+=((cnt[b[i]]*(cnt[b[i]]-1))*b[i]/2);
		for(int j=i+1;j<=m;j++)
		{
			// printf("%d:%d %d:%d\n",i,b[j],j,b[j]);
			ans+=((cnt[b[i]]*cnt[b[j]])*gcd[b[i]][b[j]]);
		}
	}
	printf("%lld",ans);
	// printf("\n_______\ntime:%llums",clock()-beg);
	return 0;
}