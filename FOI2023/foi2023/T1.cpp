#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int read()
{
	int res=0;
	char c=getchar();
	while(!('0'<=c&&c<='9'))
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=10*res+c-'0';
		c=getchar();
	}
	return res;
}

//void write(int x)
//{
//	while(x)
//	{
//		p
//	}
//}

const int N=1e7+3;
bool np[N];
int pri[N/10],cnt;
int mi[N],yg[N];//yg[i]+1,i/mi[i]
void init(int n){
    for(int i=2;i<=n;++i){
        if(!np[i])pri[++cnt]=i;
	    for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
	        np[i*pri[j]]=1;
//	        if(i<=15)
//	       		printf("%d %d\n",i,pri[j]);
	        mi[i*pri[j]]=min(mi[i*pri[j]],pri[j]);
//			yg[i*pri[j]]++;
//	        if(!yg[i*pri[j]])
	        yg[i*pri[j]]=yg[i]+1;
//			d[i * p[j]] = d[i] / num[i * p[j]] * (num[i * p[j]] + 1);
	        if(!(i%pri[j]))break;
	    }
    }
}
int main()
{
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(mi,0x3f3f3f3f,sizeof(mi));
	init(N);
	int n;
//	scanf("%d",&n);
//	cin>>n;
	n=read();
	int x,y;
	for(int i=0;i<n;i++)
	{
//		scanf("%d %d",&x,&y);
//		cin>>x>>y;
		x=read();
		y=read();
		if(yg[x]>yg[y])
		{
			swap(x,y);
		}
		while(yg[x]!=yg[y])
		{
			y=y/mi[y];
		}
//		printf("y=%d\n",y);
		while(x!=y)
		{
			x=x/mi[x];
			y=y/mi[y];
		}
		printf("%d\n",(x?x:1));
//		cout<<(x?x:1)<<"\n";
	}
//for(int i=2;i<=15;i++)
//{
//	printf("%d %d\n",i/mi[i],yg[i]+1);
//}
	return 0;
}
