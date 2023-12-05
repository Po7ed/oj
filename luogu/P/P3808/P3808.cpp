#include <iostream>
#include <queue>
using namespace std;

const int N=1145141,C=26;

char s[N];
int n;

int to[N][C],val[N],fail[N],cnt=1;
void insert(char* s)
{
	int now=0;
	for(int i=1;s[i];i++)
	{
		if(!to[now][s[i]-'a'])
		{
			to[now][s[i]-'a']=cnt++;
		}
		now=to[now][s[i]-'a'];
	}
	val[now]++;
}
void getfail()
{
	queue<int> q;
	for(int i=0;i<C;i++)
	{
		if(to[0][i])
		{
			q.push(to[0][i]);
		}
	}
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<C;i++)
		{
			if(to[u][i])
			{
				fail[to[u][i]]=to[fail[u]][i];
				q.push(to[u][i]);
			}
			else
			{
				to[u][i]=to[fail[u]][i];
			}
		}
	}
}
int query(char* t)
{
	int now=0,res=0;
	for(int i=1;t[i];i++)
	{
		now=to[now][t[i]-'a'];
		for(int j=now;j&&~val[j];j=fail[j])
		{
			res+=val[j];
			val[j]=-1;
		}
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		insert(s);
	}
	getfail();
	scanf("%s",s+1);
	printf("%d",query(s));
	return 0;
}