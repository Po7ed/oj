#include <iostream>
#include <map>
using namespace std;
typedef pair<int,int> P;
int main()
{
	map<int,P> m;
	int n,q;
	scanf("%d %d",&n,&q);
	int last=-1;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==last)m[t].second=i;
		else m[t].first=m[t].second=i;
		last=t;
	}
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(!m.count(t))printf("No Solution.\n");
		else printf("%d %d\n",m[t].first,m[t].second);
	}
	return 0;
}