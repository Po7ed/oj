#include <iostream>
#include <bitset>
using namespace std;

const int N=10,W=114514,WW=100000;
int a[N];
int vis[W];

inline int getid(int w[N])
{
	return w[1]*10000+w[2]*1000+w[3]*100+w[4]*10+w[5];
}

int main()
{
	// freopen("lock.in","r",stdin);
	// freopen("lock.out","w",stdout);
	int n,tmp,t1,t2;
	scanf("%d",&n);
//	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d %d",a+1,a+2,a+3,a+4,a+5);
		vis[getid(a)]=-0x3f3f3f3f;
		for(int j=1;j<=5;j++)// each wei
		{
			for(int k=0;k<=9;k++)// each fudu
			{
				if(k!=a[j])
				{
					tmp=k;
					swap(tmp,a[j]);
					vis[getid(a)]++;
					swap(tmp,a[j]);
				}
			}
		}
		for(int j=1;j<5;j++)// each 2 way
		{
			for(int k=1;k<=9;k++)// each fudu
			{
				t1=(a[j]+k)%N;
				t2=(a[j+1]+k)%N;
				swap(t1,a[j]);
				swap(t2,a[j+1]);
				vis[getid(a)]++;
				swap(t1,a[j]);
				swap(t2,a[j+1]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<WW;i++)
	{
//		if(vis[i]>0)
//		{
//			printf("%d\n",i);
//		}
		if(vis[i]==n)
		{
//			printf("%d",i);
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
