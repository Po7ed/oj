#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,r,q;
typedef pair<int,int> P;
/// @brief .first => index | .second => point
vector<P> v;
int w[100001];

bool cmp(P x,P y)
{
	if(x.second==y.second)return x.first<y.first;
	return x.second>y.second;
}

void game()
{
	for(int i=0;i<n;i+=2)
		if(w[v[i].first]>w[v[i+1].first])v[i].second++;
		else v[i+1].second++;
	sort(&(v.front()),&(v.back())+1,cmp);
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
	// sort(&(v.front()),&(v.back())+1,cmp);
	for(int i=v.size()-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(v[j].second==v[j+1].second&&v[j].first>v[j+1].first)swap(v[j],v[j+1]);
			else if(v[j]>v[j+1])swap(v[j],v[j+1]);
	for(int i=0;i<r;i++)
		game();
	printf("%d",v[q-1].first);
	return 0;
}