#include <bits/stdc++.h>
using namespace std;
const int maxn=500000+10;
const int inf=0x3f3f3f3f;
int n,m,a[maxn],mp[maxn],pre[maxn],pos[maxn],sum[maxn<<2],ans[maxn];

struct Query{
	int l,id;
};
vector<Query> q[maxn];

inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return (f==1)?x:-x;
}

void pushup(int rt){
	sum[rt]=min(sum[rt<<1],sum[rt<<1|1]);
}

void modify(int x,int v,int l,int r,int rt){
	if(l == r){
		sum[rt]=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(x <= mid) modify(x,v,l,mid,rt<<1);
	else modify(x,v,mid+1,r,rt<<1|1);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		return sum[rt];
	}
	int mid=(l+r)>>1,ans=inf;
	if(L <= mid) ans=min(ans,query(L,R,l,mid,rt<<1));
	if(R > mid) ans=min(ans,query(L,R,mid+1,r,rt<<1|1));
	return ans;
}

int main()
{
	
	n=read(),m=read();
	for(int i=1;i<=n;i++) mp[i]=a[i]=read();
	sort(mp+1,mp+n+1);
	int cnt=unique(mp+1,mp+n+1)-mp-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(mp+1,mp+cnt+1,a[i])-mp;
		pre[i]=pos[a[i]];pos[a[i]]=i;
	}
	int l,r;
	for(int i=1;i<=m;i++){
		l=read(),r=read();
		q[r].push_back((Query){l,i});
	}
	memset(sum,inf,sizeof(sum));
	for(int i=1;i<=n;i++){
		if(pre[i]) modify(pre[i],i-pre[i],1,n,1);
		for(int j=0;j<q[i].size();j++)
			ans[q[i][j].id]=query(q[i][j].l,i,1,n,1);
	}
	for(int i=1;i<=m;i++) printf("%d\n",(ans[i]==inf)?-1:ans[i]);
	return 0;
}