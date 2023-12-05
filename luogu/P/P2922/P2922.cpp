#include <iostream>
#include <bitset>
#include <cctype>
#include <cstring>
using namespace std;

int nxt[514114][2],siz[514114],exi[514114],tail=1;
char c,s[11451];
void insert(char* s)
{
	int len=strlen(s),now=0;
	// siz[0]++;
	for(int i=0;i<len;i++)
	{
		if(!nxt[now][s[i]-'0'])
		{
			nxt[now][s[i]-'0']=tail++;
		}
		now=nxt[now][s[i]-'0'];
		siz[now]++;
	}
	exi[now]++;
}
int find(char *s)
{
	int len=strlen(s),now=0,cnt=0;
	for(int i=0;i<len;i++)
	{
		if(!nxt[now][s[i]-'0'])
		{
			return cnt;// this
		}
		now=nxt[now][s[i]-'0'];
		cnt+=exi[now];
	}
	return cnt+siz[now]-exi[now];
}

int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			do
			{
				c=getchar();
			}
			while(!isdigit(c));
			s[j]=c;
		}
		s[k]='\0';
		insert(s);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			do
			{
				c=getchar();
			}
			while(!isdigit(c));
			s[j]=c;
		}
		s[k]='\0';
		printf("%d\n",find(s));
	}
	return 0;
}