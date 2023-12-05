#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		v.push_back(i);
	}
	int a,b,c;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		auto f=v.begin()+a-1,l=v.begin()+b;
		vector<int> t(f,l);
		v.erase(f,l);
		v.insert(v.begin()+c,t.begin(),t.end());
	}
	for(int i=0;i<10;i++)
	{
		printf("%d\n",v[i]);
	}
	return 0;
}