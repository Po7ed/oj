#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> x,pair<string,int> y)
{
	return x.second<y.second;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<string,int>> v;
	for(int i=0;i<n;i++)
	{
		int y,m,d,k;
		string name;
		cin>>name>>y>>m>>d;
		k=y*10000+m*100+d;
		v.push_back(make_pair(name,k));
	}
	reverse(v.begin(),v.end());
	stable_sort(v.begin(),v.end(),cmp);
	for(pair<string,int> t:v)
	{
		cout<<t.first<<endl;
	}
	return 0;
}