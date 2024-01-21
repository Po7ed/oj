#include <iostream>
#include <vector>
using namespace std;

const int N=1145,C=N;
int c[N],ans,tmp;
vector<int> all[N];

int main()
{
	freopen("sd.in","r",stdin);
	freopen("sd.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		all[c[i]].push_back(i);
	}
	int len;
	for(int i=1;i<=n;i++)
	{
		ans=1;
		if(all[i].empty())
		{
			printf("0 ");
			continue;
		}
		len=all[i].size();
		for(int j=1;j<len;j++)
		{
			if((all[i][j]-all[i][j-1]-1)&1)
			{
				all[i][j]=all[i][j-1];
			}
			else
			{
				ans++;
			}
		}
		printf("%d ",ans);
	}
	return 0;
}
