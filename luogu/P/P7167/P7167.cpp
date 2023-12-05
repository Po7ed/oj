#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

struct plate
{
	int d,c;
};

struct Pos
{
	int id,pos;
};

const int N=114514;
int n,q;
plate a[N];
int nxt[N];
bitset<N> vis,head;
vector<int> seq[N],sum[N];
Pos pos[N];

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].d,&a[i].c);
	}
	vector<int> v;
	for(int i=n;i;i--)
	{
		while(!v.empty()&&a[v.back()].d<=a[i].d)
		{
			v.pop_back();
		}
		if(!v.empty())
		{
			nxt[i]=v.back();
		}
		v.push_back(i);
	}
	int j,cnt;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			head[i]=true;
			j=i;
			cnt=0;
			while(j)
			{
				vis[j]=true;
				seq[i].push_back(j);
				if(j==i)
				{
					sum[i].push_back(a[i].c);
				}
				else
				{
					sum[i].push_back(sum[i].back()+a[j].c);
				}
				pos[j]={i,cnt++};
				j=nxt[j];
			}
		}
	}
	int b,w;
	while(q--)
	{
		scanf("%d %d",&b,&w);
		auto p=lower_bound(sum[pos[b].id].begin(),sum[pos[b].id].end(),
		(head[b]?w:w+sum[pos[b].id][pos[b].pos-1]));
		if(p==sum[pos[b].id].end())
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",seq[pos[b].id][p-sum[pos[b].id].begin()]);
		}
	}
	return 0;
}