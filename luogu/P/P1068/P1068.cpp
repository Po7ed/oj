#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<pair<int,int>> v;
int main()
{
	int n;
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int k,s;
		scanf("%d %d",&k,&s);
		pair<int,int> t;
		t.first=k;t.second=s;
		v.push_back(t);
		int ind=v.size()-1;
		while
		(
			(ind>0)
			&&
			(
				(
					(v[ind].second==v[ind-1].second)
					&&
					(v[ind].first<v[ind-1].first)
				)
				||
				(v[ind].second>v[ind-1].second)
			)
		)
		{
			swap(v[ind],v[ind-1]);
			ind--;
		}
	}
	int p=floor(m*(double)1.5);
	int q=v[p-1].second;
	int b=0;
	for(pair<int,int> t:v)
	{
		if(t.second>=q)b++;
		else break;
	}
	printf("%d %d\n",q,b);
	for(int i=0;i<b;i++)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}
