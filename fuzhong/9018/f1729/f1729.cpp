#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int in=0,out=0;
	vector<int> to;
	bool null=false;
};

int main()
{
	int n;
	scanf("%d",&n);
	node p[n+1];
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		p[a].to.push_back(b);
		p[a].out++;
		p[b].in++;
	}
	vector<int> s,ans;
	for(int i=1;i<=n;i++)
	{
		p[i].null=false;
		if(p[i].in==0)
		{
			s.push_back(i);
			p[i].null=true;
		}
	}
	while(!s.empty())
	{
		int f=s.front();
		ans.push_back(f);
		for(int t:p[f].to)
		{
			p[t].in--;
			if(p[t].in==0&&!p[t].null)
			{
				s.push_back(t);
				p[t].null=true;
			}
		}
		s.erase(s.begin());
	}
	if(ans.size()==n)
	{
		for(int t:ans)
		{
			printf("%d ",t);
		}
	}
	else
	{
		puts("-1");
	}
	return 0;
}