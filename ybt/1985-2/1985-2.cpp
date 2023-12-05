#include <iostream>
#include <string.h>
using namespace std;

bool b=0;
int a[100][100];
int f[100][100];

void search(int step,int index)
{
	if(f[index][step]!=-1)
	{
		b=f[index][step];
		return;
	}
	// if(b)return;
	if((step==0)&&(index==1))
	{
		b=1;
		// cout<<"b=1!!!"<<endl;
		return;
	}
	if(step==0)
	{
		return;
	}
	for(int c=0;a[index][c]!=0;c++)
	{
		// if(b)return;
		search(step-1,a[index][c]);
	}
}

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	memset(a,0,sizeof(a));
	memset(f,-1,sizeof(f));
	for(int c=0;c<m;c++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u][a[0][u]]=v;
		a[0][u]++;
		a[v][a[0][v]]=u;
		a[0][v]++;
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 		printf("%d ",a[i][j]);
	// 	puts("");
	// }
	for(int c=0;c<q;c++)
	{
		int x,l;
		scanf("%d %d",&x,&l);
		search(l,x);
		if(b)printf("Yes");
		else printf("No");
		f[x][l]=b;
		puts("");
		b=0;
	}
	return 0;
}