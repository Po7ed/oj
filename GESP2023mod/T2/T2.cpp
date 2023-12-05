#include <iostream>
#include <algorithm>
using namespace std;

inline int to(char c)
{
	return (c<='9'?c-'0':c-'A'+10);
}

inline int to(char s0,char s1)
{
	return to(s0)*0x10+to(s1);
}

struct B
{
	int id,val;
};
inline bool operator < (B x,B y)
{
	return (x.val==y.val?x.id<y.id:x.val>y.val);
}

int table[0x10],base[21][21];
B bucket[0x100];

int main()
{
	int n,m;
	scanf("%d",&n);
	char a,b;
	int t;
	string s;
	for(int i=0;i<=0xFF;i++)
	{
		bucket[i].id=i;
		bucket[i].val=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(i==1)m=s.size()/2;
		for(int j=1;j<=m;j++)
		{
			a=s[2*j-2],b=s[2*j-1];
			t=to(a,b);
			base[i][j]=t;
			bucket[t].val++;
			// printf("*%d*",t);
		}
	}
	sort(bucket,bucket+0x100);
	for(int i=0;i<=0xF;i++)
	{
		table[i]=bucket[i].id;
		if(table[i]<=0xF)printf("0");
		printf("%X",table[i]);
	}
	puts("");
	int mi,cho;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mi=0x3f3f3f3f;
			for(int k=0;k<=0xF;k++)
			{
				t=abs(table[k]-base[i][j]);
				if(mi==t?cho>k:mi>t)
				{
					mi=t;
					cho=k;
				}
			}
			// printf(" %X:%X ",base[i][j],*p);
			printf("%X",cho);
		}
		puts("");
	}
	return 0;
}