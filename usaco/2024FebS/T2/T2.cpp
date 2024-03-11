#include <iostream>
#include <algorithm>

constexpr int N=114514;
char a[N],b[N],ta[N],tb[N];
int na,nb;

int main()
{
	freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	int n,P,m;
	int to[3],ca;
	while(T--)
	{
		na=nb=1;
		scanf("%d %d\n%s\n%s",&n,&P,a+1,b+1);
		// if(T==5&&n==4&&P==1&&a[1]=='1'&&a[2]=='2'&&b[1]=='2')
		// {
		// 	printf("4\n4\n1 2\n1 3\n2 1\n3 2\n4\n1 2\n1 3\n2 1\n3 2\n1\n2 1\n5\n2 3\n1 2\n1 3\n1 2\n3 1\n6\n2 3\n1 2\n1 3\n1 2\n2 1\n3 2");
		// 	exit(0);
		// }
		for(int i=1;i<=n;i++)
		{
			if(ta[na-1]!=a[i])ta[na++]=a[i];
			if(tb[nb-1]!=b[i])tb[nb++]=b[i];
		}
		std::copy(ta+1,ta+na,a+1);
		std::copy(tb+1,tb+nb,b+1);
		n=na-1,m=nb-1;
		printf("%d\n",n+m-1);
		int ans=0;
		if(b[n]=='1')to[1]=2,to[2]=3;
		else to[1]=3,to[2]=2;
		for(int i=n;i>1;i--)printf("1 %d\n",to[a[i]-'0']),ans++;
		printf("%d 1\n",to[ca=a[1]-'0']),ans++;
		to[ca]=1;
		to[ca^3]=3;
		for(int i=m;i>1;i--)printf("2 %d\n",to[b[i]-'0']),ans++;
		printf("%d 2\n",to[b[1]-'0']),ans++;
		printf("3 1\n"),ans++;
	}
	return 0;
}