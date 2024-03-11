#include <iostream>

constexpr int N=1145141,M=N;

int n,m;
int a[N];

struct sgt
{
	struct node{int v,ls,rs;};
	node t[N<<5];
	int cnt=0;
	int rt[M];
	#define mid ((l+r)>>1)
	inline int mkn(){return ++cnt;}
	inline int cln(int frm){int ret=mkn();t[ret]=t[frm];return ret;}
	int bld(int l,int r)
	{
		int pos=mkn();
		if(l==r){t[pos].v=a[l];return pos;}
		t[pos].ls=bld(l,mid),t[pos].rs=bld(mid+1,r);
		return pos;
	}
	int mdf(int mp,int mv,int pos,int l,int r)
	{
		pos=cln(pos);
		if(l==r){t[pos].v=mv;return pos;}
		if(mp<=mid)t[pos].ls=mdf(mp,mv,t[pos].ls,l,mid);
		else t[pos].rs=mdf(mp,mv,t[pos].rs,mid+1,r);
		return pos;
	}
	int qry(int qp,int pos,int l,int r)
	{
		if(l==r)return t[pos].v;
		if(qp<=mid)return qry(qp,t[pos].ls,l,mid);
		else return qry(qp,t[pos].rs,mid+1,r);
	}
	inline void init(){rt[0]=bld(1,n);}
};

sgt tree;

int main()
{
	// freopen("out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	tree.init();
	int ver,opt,pos,val;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&ver,&opt,&pos);
		if(opt==1)
		{
			scanf("%d",&val);
			tree.rt[i]=tree.mdf(pos,val,tree.rt[ver],1,n);
		}
		else
		{
			printf("%d\n",tree.qry(pos,tree.rt[ver],1,n));
			tree.rt[i]=tree.rt[ver];
		}
	}
	return 0;
}