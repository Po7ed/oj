#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int l,r;
	int dep;
};

int main()
{
	int n;
	scanf("%d",&n);
	node tree[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&tree[i].l,&tree[i].r);
	}
	vector<node> dfs;
	tree[1].dep=1;
	dfs.push_back(tree[1]);
	node t;
	int ans=-1;
	while(!dfs.empty())
	{
		t=dfs.back();
		dfs.pop_back();
		if(t.l)
		{
			tree[t.l].dep=t.dep+1;
			dfs.push_back(tree[t.l]);
			ans=max(ans,t.dep+1);
		}
		if(t.r)
		{
			tree[t.r].dep=t.dep+1;
			dfs.push_back(tree[t.r]);
			ans=max(ans,t.dep+1);
		}
	}
	printf("%d",ans);
	return 0;
}