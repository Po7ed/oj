#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

int nxt[4000114][128],siz[4000114];
bitset<4000114> exi;
int root=0,tail=1;
inline void insert(char *s)
{
	int len=strlen(s),now=root;
	for(int i=0;i<len;i++)
	{
 		if(!nxt[now][s[i]])
		{
			nxt[now][s[i]]=tail++;
		}
		now=nxt[now][s[i]];
		siz[now]++;
	}
	exi[now]=true;
}
inline int find(char *s)
{
	int len=strlen(s),now=root;
	for(int i=0;i<len;i++)
	{
		if(!nxt[now][s[i]])
		{
			return 0;
		}
		now=nxt[now][s[i]];
	}
	return siz[now];
}
inline void clear()
{
	/* for(int i=root;i<=tail;i++)
	{
		exi[i]=false;
		for(char c='0';c<='9';c++)
		{
			nxt[i][c]=0;
		}
		for(char c='A';c<='Z';c++)
		{
			nxt[i][c]=0;
		}
		for(char c='a';c<='z';c++)
		{
			nxt[i][c]=0;
		}
		siz[i]=0;
	}
	root=0;
	tail=1; */
	root=tail++;
}

int main()
{
	int T;
	scanf("%d",&T);
	int n,q;
	char s[4000114];
	while(T--)
	{
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			insert(s);
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%s",s);
			printf("%d\n",find(s));
		}
		/* int tl=strlen(s);
		for(int i=0;i<tl;i++)
		{
			s[i]='\0';
		} */
		clear();
	}
	return 0;
}