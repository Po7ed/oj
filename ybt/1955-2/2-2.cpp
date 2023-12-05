#include <iostream>
using namespace std;
/// @brief l[i].first => index | l[i].second => point
typedef pair<int,int> P;
P l[200001];
int w[200001];
int n,r,q;


bool cmp(P x,P y)
{
	return (x.second==y.second&&x.first>y.first)||x.second>y.second;
}
int main()
{
	scanf("%d %d %d",&n,&r,&q);n*=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i].second);
		l[i].first=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	ms(1,n);
	for(int i=1;i<=r;i++)
	{
		for(int i=1;i<n;i+=2)
		{
			if(w[l[i].first]>w[l[i+1].first])l[i].second++;
			else l[i+1].second++;
		}
		ms(1,n);
	}
	printf("%d",l[q].first);
	return 0;
}