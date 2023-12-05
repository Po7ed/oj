#include <iostream>
#include <string.h>
using namespace std;
int n,c=0;
int que[10001][3];
int head=0,tail=0;
bool vis[1001][1001];

void bfs(int l,int i1,int j1,int i2,int j2)
{
	for(int i=2;i<=l+1;i++)
		for(int j=2;j<=l+1;j++)
			vis[i][j]=0;
	head=0;tail=0;
	c=0;
	que[tail][0]=i1;que[tail][1]=j1;que[tail][2]=c;tail++;tail%=10000;
	vis[i1][j1]=1;
	do
	{
		if(!vis[que[head][0]-2][que[head][1]-1])
		{
			vis[que[head][0]-2][que[head][1]-1]=1;
			que[tail][0]=que[head][0]-2;
			que[tail][1]=que[head][1]-1;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*1 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]-2][que[head][1]+1])
		{
			vis[que[head][0]-2][que[head][1]+1]=1;
			que[tail][0]=que[head][0]-2;
			que[tail][1]=que[head][1]+1;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*2 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]-1][que[head][1]-2])
		{
			vis[que[head][0]-1][que[head][1]-2]=1;
			que[tail][0]=que[head][0]-1;
			que[tail][1]=que[head][1]-2;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*3 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]-1][que[head][1]+2])
		{
			vis[que[head][0]-1][que[head][1]+2]=1;
			que[tail][0]=que[head][0]-1;
			que[tail][1]=que[head][1]+2;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*4 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]+1][que[head][1]-2])
		{
			vis[que[head][0]+1][que[head][1]-2]=1;
			que[tail][0]=que[head][0]+1;
			que[tail][1]=que[head][1]-2;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*5 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]+1][que[head][1]+2])
		{
			vis[que[head][0]+1][que[head][1]+2]=1;
			que[tail][0]=que[head][0]+1;
			que[tail][1]=que[head][1]+2;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*6 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]+2][que[head][1]-1])
		{
			vis[que[head][0]+2][que[head][1]-1]=1;
			que[tail][0]=que[head][0]+2;
			que[tail][1]=que[head][1]-1;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*7 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		if(!vis[que[head][0]+2][que[head][1]+1])
		{
			// if(head>=4850){printf("&%d %d\n",que[head][0],que[head][1]);system("pause>nul");}
			vis[que[head][0]+2][que[head][1]+1]=1;
			que[tail][0]=que[head][0]+2;
			que[tail][1]=que[head][1]+1;
			que[tail][2]=que[head][2]+1;
			tail++;tail%=10000;
		// printf("*8 %d %d\n",que[tail-1][0]-2,que[tail-1][1]-2);
			if((que[tail-1][0]==i2)&&(que[tail-1][1]==j2)){printf("%d\n",que[tail-1][2]);break;}
		}
		// printf("**%d %d %d\n",head,tail,c);
		/* if(head>=4850)for(int i=2;i<=l+1;i++)
			{for(int j=2;j<=l+1;j++)
				printf("%d ",vis[i][j]);puts("");} */
		head++;head%=10000;
		c++;
	}
	while(1);
	// system("pause>nul");
	return;
}

int main()
{
	memset(vis,1,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,i1,j1,i2,j2;
		scanf("%d",&l);
		scanf(" %d %d",&i1,&j1);i1+=2;j1+=2;
		scanf(" %d %d",&i2,&j2);i2+=2;j2+=2;
		if((i1==i2)&&(j1==j2))
			printf("0");
		else
			bfs(l,i1,j1,i2,j2);
	}
	// system("pause");
	return 0;
}