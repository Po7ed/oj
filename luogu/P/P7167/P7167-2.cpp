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

const int N=114514,L=20;
int n,q;
plate a[N];
int jmp[N][L],sum[N][L];

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
			jmp[i][0]=v.back();
			sum[i][0]=a[jmp[i][0]].c;
		}
		v.push_back(i);
	}
	for(int j=1;j<L;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[jmp[i][j-1]][j-1];
		}
	}
	int b,w,cur;
	while(q--)
	{
		scanf("%d %d",&b,&w);
		w-=a[b].c;
		if(w<=0)
		{
			printf("%d\n",b);
			continue;
		}
		cur=b;
		for(int j=L-1;j+1;j--)
		{
			if(w-sum[cur][j]>0)
			{
				w-=sum[cur][j];
				cur=jmp[cur][j];
			}
		}
		if(w)
		{
			printf("%d\n",jmp[cur][0]);
		}
		else
		{
			printf("%d\n",cur);
		}
	}
	return 0;
}