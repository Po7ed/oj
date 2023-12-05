#include <iostream>
// #include <string.h>
// #include <conio.h>
using namespace std;
#define INF 0x3f3f3f3f

int n;
int ai,aj,bi,bj;
bool vis[100][100];
char a[100][100];

int dfs(int step,int i,int j)
{
	if(i==bi&&j==bj)
	{
		return step;
	}
	int mind=INF;
	if(i!=0&&!vis[i-1][j]&&a[i][j]!=a[i-1][j])
	{
		vis[i-1][j]=true;
		int d=dfs(step+1,i-1,j);
		if(d!=-1&&d<mind)mind=d;
		vis[i-1][j]=false;
	}
	if(i!=n-1&&!vis[i+1][j]&&a[i][j]!=a[i+1][j])
	{
		vis[i+1][j]=true;
		int d=dfs(step+1,i+1,j);
		if(d!=-1&&d<mind)mind=d;
		vis[i+1][j]=false;
	}
	if(j!=0&&!vis[i][j-1]&&a[i][j]!=a[i][j-1])
	{
		vis[i][j-1]=true;
		int d=dfs(step+1,i,j-1);
		if(d!=-1&&d<mind)mind=d;
		vis[i][j-1]=false;
	}
	if(j!=n-1&&!vis[i][j+1]&&a[i][j]!=a[i][j+1])
	{
		vis[i][j+1]=true;
		int d=dfs(step+1,i,j+1);
		if(d!=-1&&d<mind)mind=d;
		vis[i][j+1]=false;
	}
	if(mind==INF)
		return -1;
	else
		return mind;
}

int main()
{
	scanf("%d\n",&n);
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
			if(a[i][j]=='A')
			{
				ai=i;aj=j;
			}
			if(a[i][j]=='B')
			{
				bi=i;bj=j;
			}
		}
	}
	vis[ai][aj]=true;
	printf("%d",dfs(0,ai,aj));
	return 0;
}
/*
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -
*/