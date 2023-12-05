#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef pair<int,pair<int,int>> P;
int main()
{
	int n,m;
	scanf("%d",&n);m=n;
	char a[102][102];
	memset(a,1,sizeof(a));
	char c;
	vector<P> v;
	for(int i=1;i<=n;i++)
	{
		scanf("\n");//输入字符数组时，注意'\n'会留在缓冲区 
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&a[i][j]);
			// if(a[i][j]=='S')
			// {
			// 	a[i][j]='1';
			// 	v.push_back(make_pair(0,make_pair(i,j)));
			// }
		}
	}
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	v.push_back(make_pair(0,make_pair(x1,y1)));
	a[x1][y1]='1';
	a[x2][y2]='T';
	int z=0x3f3f3f3f,dir=0;
	do
	{
		P t=v.front();
		v.erase(v.begin());
		if(a[t.second.first-1][t.second.second]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first-1][t.second.second]=='0')
		{
			a[t.second.first-1][t.second.second]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first-1,t.second.second)));
		}
		if(a[t.second.first][t.second.second-1]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first][t.second.second-1]=='0')
		{
			a[t.second.first][t.second.second-1]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first,t.second.second-1)));
		}
		if(a[t.second.first][t.second.second+1]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first][t.second.second+1]=='0')
		{
			a[t.second.first][t.second.second+1]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first,t.second.second+1)));
		}
		if(a[t.second.first+1][t.second.second]=='T')
		{
			printf("%d",t.first+1);
			return 0;
		}
		if(a[t.second.first+1][t.second.second]=='0')
		{
			a[t.second.first+1][t.second.second]='1';
			v.push_back(make_pair(t.first+1,make_pair(t.second.first+1,t.second.second)));
		}
	}
	while(!v.empty());
	return 0;
}