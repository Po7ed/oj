#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,r,q;
typedef pair<int,int> P;
/// @brief .first => index | .second => point
vector<P> v;
int w[100001];

void game()
{
	for(int i=0;i<n;i+=2)
	{
		bool book=0;
		if(w[v[i].first]>w[v[i+1].first])v[i].second++,book=1;
		else v[i+1].second++;
		int ii;if(book)ii=i;else ii=i+1;
		while
		(
			(ii<v.size())&&(ii>-1)&&(ii-1<v.size())&&(ii-1>-1)
			&&
			(
				v[ii].second>v[ii-1].second
				||
				(
					v[ii].second==v[ii-1].second
					&&
					v[ii].first<v[ii-1].first
				)
			)
		)
		{
			swap(v[ii],v[ii-1]);
			ii--;
		}
	}
}

bool cmp(P x,P y)
{
	return x.second>y.second;
}

int main()
{
	scanf("%d %d %d",&n,&r,&q);
	n*=2;
	for(int i=1;i<=n;i++)
	{
		P t;
		t.first=i;
		scanf("%d",&t.second);
		v.push_back(t);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	stable_sort(&(v.front()),&(v.back())+1,cmp);
	for(int i=0;i<r;i++)
		game();
	printf("%d",v[q-1].first);
	return 0;
}