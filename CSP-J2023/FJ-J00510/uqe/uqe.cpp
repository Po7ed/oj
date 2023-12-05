// tai_chou_xiang_la
#include <iostream>
//#include <vector>
//#include <cstdio>
using namespace std;

typedef long long ll;
const int N=114514;
int n,M;

inline int gcd(int a,int b)
{
	return (b?gcd(b,a%b):a);
}

inline void print(int p,int q)
{
	if(!p)return;
	int g=gcd(abs(p),abs(q));
	if(abs(p)%abs(q)==0)// zhengchu
	{
		printf("%d",p/q);
	}
	else
	{
		if(p<0&&q<0||p>0&&q>0)
		{
			printf("%d/%d",abs(p)/g,abs(q)/g);
		}
		else
		{
			printf("-%d/%d",abs(p)/g,abs(q)/g);
		}
	}
}

inline void printsqrt(int p,int q,int r)
{
	if(!p||!r)return;
	if(r==1)
	{
		print(p,q);
		return;
	}
	int g=gcd(abs(p),abs(q));
	if((p/q)*q==p)// zhengchu
	{
		if(p/q==1)
		{
			printf("+sqrt(%d)",r);
		}
		else
		{
			if(p/q>0)
			{
				printf("+%d*sqrt(%d)",p/q,r);
			 } 
			 else
			 {
			 	printf("%d*sqrt(%d)",p/q,r);
			 }
			
		}
		
	}
	else
	{
		if(p<0&&q<0||p>0&&q>0)
		{
			if(abs(p)/g==1||abs(p)/g==-1)
			{
				if(abs(q)/g==1||abs(q)/g==-1)
				{
					printf("+sqrt(%d)",r);
				}
				else
				{
					printf("+sqrt(%d)/%d",r,abs(q)/g);
				}
			}
			else
			{
				if(abs(q)/g==1||abs(q)/g==-1)
				{
					if(abs(p)/g>0)
					{
						printf("+%d*sqrt(%d)",abs(p)/g,r);
					}
					else
					{
						printf("%d*sqrt(%d)",abs(p)/g,r);
					}
				}
				else
				{
					if(abs(p)/g>0)
					{
						printf("+%d*sqrt(%d)/%d",abs(p)/g,r,abs(q)/g);
					}
					else
					{
						printf("%d*sqrt(%d)/%d",abs(p)/g,r,abs(q)/g);
					 } 
				}
			 } 
		}
		else
		{
			if(abs(p)/g==1||abs(p)/g==-1)
			{
				if(abs(q)/g==1||abs(q)/g==-1)
				{
					printf("-sqrt(%d)",r);
				}
				else
				{
					printf("-sqrt(%d)/%d",r,abs(q)/g);
				}
			}
			else
			{
				if(abs(q)/g==1||abs(q)/g==-1)
				{
					printf("-%d*sqrt(%d)",abs(p)/g,r);
				}
				else
				{
					printf("-%d*sqrt(%d)/%d",abs(p)/g,r,abs(q)/g);
				}
			 } 
		}
	}
//	puts("");
}

pair<int,int> getsqrt(int r)//r>=0
{
//	puts("\nSB1");
	if(!r)return {-1,-1};
	int res=1;
	for(int i=2;i*i<=r;i++)
	{
		while(r%(i*i)==0&&r)
		{
			res*=i;
			r/=(i*i);
//			printf("r%d\n",r);
		}
	}
//	puts("\nSB2");
	if(!r)
	{
		return {1,-1};
	}
	return {res,r};
}

int main()
{
	// freopen("uqe.in","r",stdin);
	// freopen("uqe.out","w",stdout);
	scanf("%d %d",&n,&M);
//	printf("%d %d\n",n,M);
	int a,b,c;
	pair<int,int> s;
	while(n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(b*b<4*a*c)
		{
			puts("NO");
			continue;
		}
		s=getsqrt(b*b-4*a*c);
		if(s.second==1)
		{
			print(-b+s.first,2*a);
			puts("");
			continue;
		}
//		else
//		{
//			printf("**%d\n",s.first);
//		}
		print(-b,2*a);
		if(s.second!=-1)
		{
//			puts("\na"); 
//			printf("+");
			int p=s.first,q=2*a,r=s.second;
//			printf("*%d %d\n",p,q);
			printsqrt(p,q,r);
		}
		puts("");
	}
	return 0;
}
