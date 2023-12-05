#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
int main()
{
	double p[]={1E8,1E7,1E6,1E5,1E4,1E3,1E2,1E1,1E0};
	int n,m=-1;
	scanf("%d",&n);
	string s[n];
	pair<int,int> v[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		int l=s[i].size();
		for(int j=0;j<l;j++)
		{
			v[i].first+=((s[i][j]-'0')*p[j]);
		}
		v[i].second=i;
	}
	sort(v,v+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<s[v[i].second];
	}
	cout<<endl;
	return 0;
}