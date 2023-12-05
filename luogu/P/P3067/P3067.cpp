#include <iostream>
#include <bitset>
#include <map>
#include <vector>
using namespace std;
int a[21];
int n;

int ans,mid;
map<int,vector<int>> stw;
bitset<2097152> can;

bool type=true;
void dfs(int dep=0,int sum=0,int way=0)
{
	if(type&&dep==mid)
	{
		stw[sum].push_back(way);
		return;
	}
	else if(!type&&dep==n)
	{
		for(int fnt:stw[sum])
		{
			can[fnt|way]=true;
		}
		return;
	}
	dfs(dep+1,sum,way);
	dfs(dep+1,sum+a[dep+1],way+(1<<dep));
	dfs(dep+1,sum-a[dep+1],way+(1<<dep));
}

int main()
{
	scanf("%d",&n);
	mid=n/2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	dfs();
	type=false;
	dfs(mid);
	printf("%d",can.count()-1);
	return 0;
}