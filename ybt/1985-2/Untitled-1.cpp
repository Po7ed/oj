#include <iostream>
#include <string.h>
using namespace std;

bool b=0;
int a[1000][100];//[worker u] 's[connection index]is v
int f[1000][100];//work list's result [worker idx][step]-->b(-1/1/0)

void search(int step,int index)// :left step,  index : worker index
{
	if(f[index][step]!=-1)//f[index][step]has been searched
	{
		if(b!=1)
		b=f[index][step];
	//printf("f[index][step]%d,%d,%d",index,step,f[index][step]);
		return;
	}
	// if(b)return;
	if((step==0)&&(index==1))//this step is step0 and connect work0-->b
	{
		b=1;
		// cout<<"b=1!!!"<<endl;
		return;
	}
	if(step==0)//this step is step0
	{
		return;
	}
	for(int c=0;a[index][c]!=0;c++)//arch all of this index's conections
	{
		// if(b)return;
		search(step-1,a[index][c]);//ep-1,,search index's next conections 
	}
}

int main()
{
	int n,m,q;//n:worker number,m:connect number ,q:list number
	scanf("%d %d %d",&n,&m,&q);
	memset(a,0,sizeof(a));
	memset(f,-1,sizeof(f));//f-->-1
	for(int c=0;c<m;c++)// connections
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u][a[0][u]]=v;// [worker u] 's[connection index]is v
		a[0][u]++;//[connection number]of [worker u] 
		a[v][a[0][v]]=u;
		a[0][v]++;//worker v's connection number
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=n;j++)
	// 		printf("%d ",a[i][j]);
	// 	puts("");
	// }
	for(int c=0;c<q;c++)//ore lists
	{
		int x,l;
		scanf("%d %d",&x,&l);//work index,  step 
		search(l,x);
		if(b)printf("Yes");
		else printf("No");
		f[x][l]=b;//f[x][l]has searched flag b=0/1
		puts("");
		b=0;
	}
	return 0;
}