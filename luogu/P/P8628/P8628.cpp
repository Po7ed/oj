#include <iostream>
#include <string.h>
// #include <conio.h>
using namespace std;
#define INF 0x3f3f3f3f

int main()
{
	int n;
	scanf("%d\n",&n);
	char a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==n-1)
			{
				scanf("%c\n",&a[i][j]);
			}
			else
			{
				scanf("%c ",&a[i][j]);
			}
		}
	}
	int e[n*n][n*n];
	memset(e,INF,sizeof(e));
	int A,B;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			switch(a[i][j])
			{
				case 'A':
					A=n*i+j;
				break;
				case 'B':
					B=n*i+j;
				break;
				case '+':
					if(i!=0&&(a[i-1][j]=='-'||a[i-1][j]=='A'||a[i-1][j]=='B'))
					{
						e[n*i+j][n*(i-1)+j]=1;
						e[n*(i-1)+j][n*i+j]=1;
					}
					if(i!=n-1&&(a[i+1][j]=='-'||a[i+1][j]=='A'||a[i+1][j]=='B'))
					{
						e[n*i+j][n*(i+1)+j]=1;
						e[n*(i+1)+j][n*i+j]=1;
					}
					if(j!=0&&(a[i][j-1]=='-'||a[i][j-1]=='A'||a[i][j-1]=='B'))
					{
						e[n*i+j][n*i+(j-1)]=1;
						e[n*i+(j-1)][n*i+j]=1;
					}
					if(j!=n-1&&(a[i][j+1]=='-'||a[i][j+1]=='A'||a[i][j+1]=='B'))
					{
						e[n*i+j][n*i+(j+1)]=1;
						e[n*i+(j+1)][n*i+j]=1;
					}
				break;
				case '-':
					if(i!=0&&(a[i-1][j]=='+'||a[i-1][j]=='A'||a[i-1][j]=='B'))
					{
						e[n*i+j][n*(i-1)+j]=1;
						e[n*(i-1)+j][n*i+j]=1;
					}
					if(i!=n-1&&(a[i+1][j]=='+'||a[i+1][j]=='A'||a[i+1][j]=='B'))
					{
						e[n*i+j][n*(i+1)+j]=1;
						e[n*(i+1)+j][n*i+j]=1;
					}
					if(j!=0&&(a[i][j-1]=='+'||a[i][j-1]=='A'||a[i][j-1]=='B'))
					{
						e[n*i+j][n*i+(j-1)]=1;
						e[n*i+(j-1)][n*i+j]=1;
					}
					if(j!=n-1&&(a[i][j+1]=='+'||a[i][j+1]=='A'||a[i][j+1]=='B'))
					{
						e[n*i+j][n*i+(j+1)]=1;
						e[n*i+(j+1)][n*i+j]=1;
					}
				break;
			}
		}
	}
	int dist[n*n];
	bool vis[n*n];
	memset(vis,false,sizeof(vis));
	vis[A]=true;
	for(int i=0;i<n*n;i++)
	{
		if(!vis[i])
		{
			dist[i]=e[A][i];
		}
	}
	while(true)
	{
		int mind=INF,t=-1;
		for(int j=0;j<n*n;j++)
		{
			if(!vis[j]&&dist[j]<mind)
			{
				mind=dist[j];
				t=j;
			}
		}
		if(t==-1)
		{
			break;
		}
		vis[t]=true;
		for(int j=0;j<n*n;j++)
		{
			if(e[t][j]!=INF&&dist[j]>dist[t]+e[t][j])
			{
				dist[j]=dist[t]+e[t][j];
			}
		}
	}
	if(dist[B]>=INF)
		puts("-1");
	else
		printf("%d",dist[B]);
	return 0;
}