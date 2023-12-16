#include <iostream>
#include <vector>
using namespace std;

constexpr int N=20,M=1<<N;
int a[N],s[M];
int n,m,all;

vector<int> ans;

int main()
{
	// freopen("out","w",stdout);
	scanf("%d %d",&n,&m);all=1<<n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		s[1<<i]=a[i];
	}
	for(int i=1,j;i<all;i++)
	{
		j=i&(-i);
		s[i]=s[i^j]+s[j];
		if(s[i]==m&&__builtin_popcount(i)>=ans.size())
		{
			ans.clear();
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1)
				{
					ans.push_back(a[j]);
				}
			}
		}
	}
	if(ans.empty())
	{
		printf("No Answer!");
	}
	else
	{
		int l=ans.size();
		for(int i=0;i<l;i++)
		{
			printf("%d",ans[i]);
			if(i!=l-1)printf(" ");
		}
	}
	return 0;
}