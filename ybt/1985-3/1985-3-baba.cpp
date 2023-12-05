#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int link[100001][2];//conection u--v
int l[100001][2];//st u--l
int que[1000001];//queue u or v
int dist[100001][2];//the most shortest distance
int wkidx=-1,step=1,head,tail,tailtmp,lon;
int n,m,q,k=1;//n:worker number,m:connect number ,q:list number
vector<int> a[100001];

int main()
{
	//freopen("P5663_18.in","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dist,-1,sizeof(dist));
	scanf("%d %d %d",&n,&m,&q);
	//100000
	for(int i=1;i<=m;i++)// connections
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
		/* link[i][0]=u;
		link[i][1]=v; [worker u] 's[connection index]is v */
	}
	//100000
	for(int i=1;i<=q;i++)// work list
	{
		int w,y;
		scanf("%d %d",&w,&y);
		l[i][0]=w;
		l[i][1]=y;
	}
	que[1]=1;dist[1][0]=2;
	head=1;
	tail=2;
	do
	{
		int len=tail-head;
		for(int i=1;i<=len;i++)
		{
			for(int j=0;j<a[que[head]].size();j++)
			{
				// if(a[que[head]][j]==41840){freopen("CON","r",stdin);freopen("CON","w",stdout);system("pause");freopen("P5663_18.in","r",stdin);freopen("out.txt","w",stdout);}
				if(dist[a[que[head]][j]][step%2]==-1)
				{
					dist[a[que[head]][j]][step%2]=step;
					// if(dist[que[head]][!(step%2)]!=-1)
					// 	dist[que[head]][!(step%2)]=step+1;
					que[tail]=a[que[head]][j];
					tail++;
				}
			//	else if(dist[a[que[head]][j]][0]==-1||dist[a[que[head]][j]][1]==-1)
				//	que[tail]=a[que[head]][j],tail++;
			}
			/* for(int j=1;j<=m;j++)//100000
			{
				if(link[j][0]==que[head])
				{
					if(dist[link[j][1]][step%2]==-1)
					{
						dist[link[j][1]][step%2]=step;
						que[tail]=link[j][1];
						tail++;
					}
				}
				if(link[j][1]==que[head])
				{
					if(dist[link[j][0]][step%2]==-1)
					{
						dist[link[j][0]][step%2]=step;
						que[tail]=link[j][0];
						tail++;
					}
				}
			} */
			head++;
		}
		step++;
	}
	while (head!=tail);
	for(int i=1;i<=q;i++)
	{
		if((l[i][1]%2==0)&&(dist[l[i][0]][0]!=-1)&&(l[i][1]>=dist[l[i][0]][0]))
		{
			printf("Yes\n");
		}
		else if((l[i][1]%2!=0)&&(dist[l[i][0]][1]!=-1)&&(l[i][1]>=dist[l[i][0]][1]))
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	// freopen("CON","w",stdout);
	// cout<<dist[41841][0]<<" "<<dist[41841][1]<<endl;
	return 0;
}/*
5 5 5
1 2
2 3
3 4
4 5
1 5
1 1
1 2
1 3
1 4
1 5*/