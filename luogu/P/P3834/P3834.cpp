#include <iostream>
#include <algorithm>
#include <map>
using std::copy;
using std::sort;
using std::unique;
using std::map;

constexpr int N=214514;
int a[N],b[N];
int n,m;

struct sgt
{
	struct node{int ls,rs,sum;};
	node t[N<<5];int cnt;
	int rt[N];
	#define mid ((l+r)>>1)
	inline int mkn(){return ++cnt;}
	inline int cln(int frm){int ret=mkn();t[ret]=t[frm];return ret;}
	int bld(int l,int r)
	{
		int pos=mkn();
		if(l==r)return pos;
		t[pos].ls=bld(l,mid);
		t[pos].rs=bld(mid+1,r);
		return pos;
	}
	int mdf(int mp,int pos,int l,int r)
	{
		pos=cln(pos);t[pos].sum++;
		if(l==r)return pos;
		if(mp<=mid)t[pos].ls=mdf(mp,t[pos].ls,l,mid);
		else t[pos].rs=mdf(mp,t[pos].rs,mid+1,r);
		return pos;
	}
	int qry(int k,int u,int v,int l,int r)
	{
		if(l==r)return l;
		int lsz=t[t[v].ls].sum-t[t[u].ls].sum;
		if(k<=lsz)return qry(k,t[u].ls,t[v].ls,l,mid);
		else return qry(k-lsz,t[u].rs,t[v].rs,mid+1,r);
	}
};

sgt tree;
map<int,int> id;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int l,r,k;
	copy(a+1,a+n+1,b+1);
	sort(b+1,b+n+1);
	int tot=unique(b+1,b+n+1)-b-1;
	tree.rt[0]=tree.bld(1,tot);
	for(int i=1;i<=tot;i++)id[b[i]]=i;
	for(int i=1;i<=n;i++)tree.rt[i]=tree.mdf(id[a[i]],tree.rt[i-1],1,tot);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&l,&r,&k);
		printf("%d\n",b[tree.qry(k,tree.rt[l-1],tree.rt[r],1,tot)]);
	}
	return 0;
}