#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

/* #include <cstdio>
#include <cctype>
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch(){
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline int getint(){
    int res = 0, neg = 0, ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
} */

int n;
int a[114514],mex[114514],cur;
ll sum[311451];int rmi[311451];
int tag[311451];
bitset<114514> b;
ll ans;
vector<int> las[114514];

#define ls (pos<<1)
#define rs (pos<<1|1)
#define md ((l+r)>>1)

inline void update(int pos)
{
	sum[pos]=sum[ls]+sum[rs];
	rmi[pos]=rmi[rs];
}

void build(int pos,int l,int r)
{
	if(l==r)
	{
		sum[pos]=(ll)mex[l];
		rmi[pos]=mex[l];
		return;
	}
	int mid=md;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(pos);
}

inline void mktag(int pos,int len,int x)
{
	sum[pos]=len*x;
	rmi[pos]=x;
	tag[pos]=x;
}

inline void pdtag(int pos,int l,int r)
{
	int mid=md;
	mktag(ls,mid-l+1,tag[pos]);
	mktag(rs,r-mid,tag[pos]);
	tag[pos]=-1;
}

void modify(int pos,int l,int r,int ml,int mr,int x)
{
	if(tag[pos]!=-1&&l!=r)
	{
		pdtag(pos,l,r);//why?
	}
	if(ml<=l&&r<=mr)
	{
		mktag(pos,r-l+1,x);
		return;
	}
	int mid=md;
	if(ml<=mid)
	{
		modify(ls,l,mid,ml,mr,x);
	}
	if(mid<mr)
	{
		modify(rs,mid+1,r,ml,mr,x);
	}
	update(pos);
	return;
}

ll query(int pos,int l,int r,int ql,int qr)
{
	ll ret=0;
	if(ql<=l&&r<=qr)
	{
		return (ll)sum[pos];
	}

	if(tag[pos]!=-1)
	{
		pdtag(pos,l,r);
	}

	int mid=md;

	if(ql<=mid)
	{
		ret=query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		ret+=query(rs,mid+1,r,ql,qr);
	}
	return ret;
}

bool cmp(int val,int ele)
{
	return val>ele;
}

int srchq(int i)
{
	int l=1,r=n,pos=1;
	if(query(1,1,n,1,1)<a[i])
	{
		return -1;
	}
	while(l!=r&&tag[pos]==-1)
	{
		if(a[i]>rmi[ls])
		{
			r=md;
			pos=ls;
		}
		else
		{
			l=md+1;
			pos=rs;
		}
	}
	l=r=l-1;
	if(l>=i)
	{
		return i;
	}
	return r;
}

inline void mifill(int p,int i)
{
	int y;
	for(int j=p;j<i;j++)
	{
		y=query(1,1,n,j,j);
		if(y>a[i])
		{
			modify(1,1,n,j,j,a[i]);
		}
		else
		{
			break;
		}
	}
	modify(1,1,n,i,i,0);
	return;
}

void srch(int i)
{
	int p=0;
	/* for(p=i-1;p>0;p--)
	{
		if(a[p]==a[i])
		{
			break;
		}
	} */
	las[a[i]].pop_back();
	p=las[a[i]].back()+1;
	// printf("i:%d p:%d\n",i,p);
	// p++;
	// mifill(p,i);
	//	query(1,1,n,p,q);
	int q=srchq(i);
	if(p<=q)
		modify(1,1,n,p,q,a[i]);
	// modify(1,1,n,i,i,0);
	return;
}

inline void init()
{
	b.reset();
	fill(tag,tag+311451,-1);
}
int main()
{
	// freopen("mex.in", "r", stdin);
	// freopen("mex.out", "w", stdout);
	init();
	scanf("%d",&n);
	// n=getint();
	for(int i=0;i<=n;i++)
	{
		las[i].push_back(0);
	}
	// for(int i=1;i<=n;i++)printf("%d ",i%10);
	// puts("");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		// a[i]=getint();
		las[a[i]].push_back(i);
	}
	for(int i=n;i>0;i--)
	{
		b[a[i]]=true;
		while(b[cur])
		{
			cur++;
		}
		mex[i]=cur;
	}
	build(1,1,n);
	ans=(ll)sum[1];
	for(int i=n;i>1;i--)
	{
		srch(i);
		// ans+=(ll)sum[1];
		ans+=query(1,1,n,1,i-1);
		// modify(1,1,n,i,i,0);
		// for(int i=1;i<=n;i++)
		// {
		// 	printf("%d ",query(1,1,n,i,i));
		// }
		// puts("");
		// printf("%lld\n",ans);
	}
	printf("%lld",ans);
	return 0;
}
/* 
21
3 0 2 1 9 6 4 0 8 8 9 2 2 4 9 2 3 1 5 0 6
 */