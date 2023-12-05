#include <iostream>
#include <queue>
using namespace std;

inline bool p(int a,int b,int c)
{
	return (b-a==c-b);
}

typedef struct Case
{
	int a,b,da,db;
}C;
#define a1 t.a
#define b1 t.b
#define da1 t.da
#define db1 t.db
/*
void clear(queue<C>&q) 
{
    queue<C> empty;
    swap(empty,q);
}
*/
int main()
{
	int T,n;
	int x,a,b,c;
	scanf("%d",&T);
	queue<C> q;
	C t,tt;
	int l;
	for(int i=0;i<T;i++)
	{
		scanf("%d\n",&n);
		q=queue<C>();
		if(n<=4)
		{
			for(int j=1;j<=n;j++)scanf("%d",&x);
			puts("Yes");
			continue;
		}

		scanf("%d %d %d",&a,&b,&c);
		if(p(a,b,c))
		{
			q.push({c,-1,c-b,-1});
		}
		else
		{
			q.push({c,a,c-b,-1});
			q.push({c,b,c-a,-1});
			q.push({b,c,b-a,-1});
		}
		for(int j=4;j<=n;j++)
		{
			if(q.empty())
			{
				scanf("%d",&x);
				continue;
			}
			scanf("%d",&x);
			l=q.size();
			for(int k=0;k<l;k++)
			{
				tt=q.front();
				q.pop();
				t=tt;
				if((x-a1)==da1)
				{
					a1=x;
					q.push(t);
				}
				t=tt;
				if(b1==-1)//b1 isn't someone
				{
					b1=x;//creat eto-b1
				}
				else//b1 is someone
				{
					if(db1==-1)//only one,no gangling
					{//creat gnagling
						db1=x-b1;
						b1=x;
					}
					else
					{//have gangling
						if(x-b1==db1)
						{
							b1=x;//welcome to b1,we are tongzhi now
						}
						else//doesn't match b1
						{
							continue;
						}
					}
				}
				q.push(t);
			}
		}
		if(q.empty())
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	return 0;
}

/*
4
5
1 2 3 5 7
5
1 3 6 10 15
8
1 2 5 6 9 10 13 14
6
1 4 6 7 8 9
*/