#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v;
	vector<int> e[n+1];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",e[i].size());
		sort(e[i].begin(),e[i].end(),greater<int>());
		for(int to:e[i])
		{
			printf("%d ",to);
		}
		puts("");
	}
	return 0;
}