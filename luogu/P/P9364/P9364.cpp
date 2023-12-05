#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;

const int L=114514;

struct trie
{
	int a[L][26],cnt=1;
	bitset<L> /* exi, */per;
	inline int insert(char *s,int len)
	{
		int cur=0;
		for(int i=0;i<len;i++)
		{
			if(!a[cur][s[i]-'a'])
			{
				a[cur][s[i]-'a']=cnt++;
			}
			cur=a[cur][s[i]-'a'];
		}
		// exi[cur]=true;
		// if(len==1)
		// {
		// 	per[cur]=true;
		// }
		return cur;
	}
	inline bool find(char *s,int len)
	{
		int cur=0;
		for(int i=0;i<len;i++)
		{
			if(!a[cur][s[i]-'a'])
			{
				return false;
			}
			cur=a[cur][s[i]-'a'];
		}
		return per[cur];
	}
};

struct tstr
{
	char *beg;
	int len;
	friend inline bool operator < (tstr x,tstr y)
	{
		return x.len<y.len;
	}
};

char s[L];
tstr a[L];
trie t;
int main()
{
	int n;
	scanf("%d",&n);
	int ans=-1,len,cur,stail=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+stail);
		a[i].len=strlen(s+stail);
		a[i].beg=s+stail;
		stail+=a[i].len;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cur=t.insert(a[i].beg,a[i].len);
		if(a[i].len==1||t.find(a[i].beg+1,a[i].len-1)&&t.find(a[i].beg,a[i].len-1))
		{
			t.per[cur]=true;
			ans=max(ans,a[i].len);
		}
	}
	printf("%d",ans);
	return 0;
}