#include <iostream>
#include <vector>
using namespace std;

int n,m;

double value(int z)
{
	return 100.0-(100.0/(double)z);
}

double bfs(int a,int b,vector<pair<int,double>> v[n])
{

}

int main()
{
	scanf("%d %d",&n,&m);
	vector<pair<int,double>> v[n];
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		v[x].push_back(make_pair(y,value(z)));
		v[].push_back(make_pair(x,value(z)));
	}
	return 0;
}