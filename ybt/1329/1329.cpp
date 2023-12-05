#include <iostream>
#include <string.h>
using namespace std;
int n,m,c=0;
bool vis[101][101];
int que[10000][2];
int head=0,tail=0;

void bfs()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j])
			{
				que[tail][0]=i;que[tail][1]=j;tail++;tail%=n*m;
				vis[que[head][0]][que[head][1]]=1;
				do
				{
					if(!vis[que[head][0]-1][que[head][1]])
					{
						que[tail][0]=que[head][0]-1;
						que[tail][1]=que[head][1];
						tail++;tail%=n*m;
						vis[que[head][0]-1][que[head][1]]=1;
					}
					if(!vis[que[head][0]+1][que[head][1]])
					{
						que[tail][0]=que[head][0]+1;
						que[tail][1]=que[head][1];
						tail++;tail%=n*m;
						vis[que[head][0]+1][que[head][1]]=1;
					}
					if(!vis[que[head][0]][que[head][1]-1])
					{
						que[tail][0]=que[head][0];
						que[tail][1]=que[head][1]-1;
						tail++;tail%=n*m;
						vis[que[head][0]][que[head][1]-1]=1;
					}
					if(!vis[que[head][0]][que[head][1]+1])
					{
						que[tail][0]=que[head][0];
						que[tail][1]=que[head][1]+1;
						tail++;tail%=n*m;
						vis[que[head][0]][que[head][1]+1]=1;
					}
					head++;head%=n*m;
				}
				while(head!=tail);
				c++;
				head=0;tail=0;
			}
	return;
}

int main()
{
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			vis[i][j]=1;
	scanf("%d %d",&n,&m);
	cin.ignore(1024,'\n');
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		for(int j=1;j<=m;j++)
			if(s[j-1]-48)vis[i][j]=0;
	}
	bfs();
	printf("%d",c);
	return 0;
}