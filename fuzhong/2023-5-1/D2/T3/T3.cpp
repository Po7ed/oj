#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	freopen("stack.in","r",stdin);
	freopen("stack.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> v[n+1];
	string op;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		cin>>op;
		if(op=="push")
		{
			scanf("%d %d %d",&x,&y,&z);
			v[z].insert(v[z].end(),x,y);
		}
		else if(op=="pop")
		{
			scanf("%d %d",&x,&z);
			printf("%d\n",*(v[z].end()-x));
			v[z].erase(v[z].end()-x,v[z].end());
		}
		else if(op=="put")
		{
			scanf("%d %d",&x,&y);
			reverse(v[x].begin(),v[x].end());
			v[y].insert(v[y].end(),v[x].begin(),v[x].end());
			v[x].clear();
		}
	}
	return 0;
}