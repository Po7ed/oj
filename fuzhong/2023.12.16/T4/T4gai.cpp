#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
 * 20:03 开订
 * long long
 * 20:12 订完了，交
 * Killed: Segmentation fault
 * md
 * 20:19 开大，特判越界，交
 * 20:27 试试 bfs
 * 咦~ 还没 WA，先 RE 了
 * 20:29 再试试
 * 一样的
 * 鉴定为 bfs
 * 20:30 开大 bfs 相关数组
 * 理论上不会 RE 的啊
 * 20:32 康康 inputs
 * input 时 RE？？？
 * 弱智
 * 并不
 * 
 * 到 bfs 都没问题
 * 
 * wssb| 调试用 &&0 忘关
 * ~~忘关就是开啦~~
 * 
 * md
 * 编译一下发现忘打 = temp line 140）
 * 弱智
 * 20:44 交！
 * File Error fxxk
 * 
 * 20:45 试试 modify
 * 
 * CE                 FXXK
 * 
 * 20:47 交，RE，取之，modify
 * 查 modify 罢
 * 20:48 逝世 build
 * WA
 * 看来是 modify 的问题
 * 
 * 20:58 对之前的 40 pts，交
 * 21:04 判
 * 终于……
 * 判松点试试
 * 
 * 忽然懂了
 * 有些节点是叶子，没有孩子，导致修改 [l,r]=[beg[u],end[u]]=[0,0]。
 * 然后永远修不到，导致 RE。
 * 放宽所有越界判断
 * 21:12 交
 * 60 pts
 * 说明全是线段树黑箱外部原因。
 * 放宽外部判断到底线。
 * 交
 * 60 pts
 * 缩紧seg数组
 * 60 pts
 * 与seg无关
 * 看来它是好人
 * *****
 * Part II 分块优化
 * 牛逼！！！
 * 只能说榜1dalao太秀了
 * 21:29 开订暴力
 * 21:43 订完
 * 21:49 忘了样例里有 *
 * 交
 * ***************AC！！！***********************
 */

typedef long long ll;
constexpr int N=414514;
constexpr ll mod=998244353;
int n,m,q;
vector<int> e[N];

namespace force
{
	ll a[N],tag[N];
	int deg[N];
	void solve()
	{
		vector<int> dpos;
		#define du deg[u]
		#define dv deg[v]
		for(int u=1,cnt;u<=n;u++)//^ u->v
		{
			cnt=0;
			for(int v:e[u])//^ 小度点连大度点
			{
				if(du^dv?du>dv:u>v)
				{
					dpos.push_back(cnt);
				}
				cnt++;
			}
			while(!dpos.empty())e[u].erase(e[u].begin()+dpos.back()),dpos.pop_back();
		}
		int o,u;
		ll p,res;
		for(int i=1;i<=q;i++)
		{
			scanf("%d %d",&o,&u);
			if(o==3)// query
			{
				res=(a[u]+tag[u])%mod;
				for(int v:e[u])(res+=tag[v])%=mod;// 捅大度点的 tag
				printf("%lld\n",res);
			}
			else// modify
			{
				scanf("%lld",&p);
				(tag[u]+=p)%=mod;// 不重复加，大度、小度点加 tag
				for(int v:e[u])(a[v]+=p)%=mod;// 暴力加大度点的 a
			}
		}
	}
}// namespace force

namespace tree
{
	int bfn[N],fa[N],beg[N],end[N];
	struct node
	{
		int u,f;
	};
	void bfs()
	{
		queue<node> q;
		q.push({1,0});
		int u,f,cnt=0;
		bfn[1]=++cnt;
		while(!q.empty())
		{
			u=q.front().u;
			f=q.front().f;
			fa[u]=f;
			q.pop();
			for(int v:e[u])if(v!=f)
			{
				bfn[v]=++cnt;
				q.push({v,u});
				if(!beg[u])beg[u]=bfn[v];
				end[u]=bfn[v];
			}
		}
		//todo test
		// printf("**%d,%d:%d**",beg[1],end[1],bfn[n]);
	}
	
	ll seg[N<<2],tagm[N<<2],tagp[N<<2],len[N<<2];
	inline void init()
	{
		return fill(tagm,tagm+(N<<2),1ll);
	}
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	inline void update(int pos)
	{
		// if(pos>=(N<<2))return;
		seg[pos]=(seg[ls]+seg[rs])%mod;
	}
	void build(int pos=1,int l=1,int r=n)
	{
		len[pos]=r-l+1;
		if(l==r)return;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	#define mul true
	#define pls false
	inline void mktag(int pos,ll x,bool typ)
	{
		// if(pos>=(N<<2))return;
		if(typ==mul)//mul
		{
			(tagm[pos]*=x)%=mod;
			(tagp[pos]*=x)%=mod;
			(seg [pos]*=x)%=mod;
		}
		else//pls
		{
			(tagp[pos]+=x)%=mod;
			(seg[pos]+=(len[pos]*x))%=mod;//! ohh fxxk you
		}
	}
	inline void pdtag(int pos)
	{
		// if(pos>=(N<<2))return;
		/* if(ls<(N<<2)) */mktag(ls,tagm[pos],mul),mktag(ls,tagp[pos],pls);
		/* if(rs<(N<<2)) */mktag(rs,tagm[pos],mul),mktag(rs,tagp[pos],pls);
		tagp[pos]=0ll;
		tagm[pos]=1ll;
	}
	void modify(int ml,int mr,ll mv,bool typ,int pos=1,int l=1,int r=n)
	{
		// printf("pos%d l%d r%d (ml%d mr%d mv%d)\n",pos,l,r,ml,mr,mv);
		if(ml<=l&&r<=mr)return mktag(pos,mv,typ);
		// have tag,push down tag
		if((tagp[pos]||tagm[pos]-1)/* &&l!=r */)pdtag(pos);
		if(ml<=mid)modify(ml,mr,mv,typ,ls,l,mid);
		if(mid<mr)modify(ml,mr,mv,typ,rs,mid+1,r);
		update(pos);
	}
	ll query(int qp,int pos=1,int l=1,int r=n)
	{
		if(l==r)return seg[pos]%=mod;
		if((tagp[pos]||tagm[pos]-1)/* &&l!=r */)pdtag(pos);
		if(qp<=mid)return query(qp,ls,l,mid);
		else if(mid<qp)return query(qp,rs,mid+1,r);
	}
	void solve()
	{
		init();
		build();
		// puts("end build()");
		// exit(0);
		int o,u;
		ll p;
		// for(int i=1;i<=n;i++)
		// {
		// 	printf("%d:%d ",i,bfn[i]);
		// }
		for(int i=1;i<=q;i++)
		{
			scanf("%d %d",&o,&u);
			// printf("%d\n",i);
			if(o==3)
			{
				// puts("modify is ok");
				// exit(0);//! fxxk you
				printf("%lld\n",query(bfn[u]));
			}
			else
			{
				scanf("%lld",&p);
				if(o==1)
				{
					if(fa[u])modify(bfn[fa[u]],bfn[fa[u]],p,pls);
					// puts("modify father end;");
					modify(bfn[u],bfn[u],p,pls);
					if(beg[u])modify(beg[u],end[u],p,pls);
				}
				else
				{
					if(fa[u])modify(bfn[fa[u]],bfn[fa[u]],p,mul);
					modify(bfn[u],bfn[u],p,mul);
					if(beg[u])modify(beg[u],end[u],p,mul);//! 看来是这里的问题
				}
			}
		}
		return;
	}
}// namespace tree

int main()
{
	freopen("garden.in","r",stdin);
	freopen("garden.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		force::deg[u]++,force::deg[v]++;
	}
	// puts("end of inputs");
	// return 0;
	if(n<=100000/* &&0 */)// force
	{
		force::solve();
	}
	else// tree
	{
		tree::bfs();//! 测试
		// for(int i=1;i<=n;i++)
		// {
		// 	if(!)
		// }
		// puts("end of bfs");
		// return 0;
		tree::solve();
	}
	return 0;
}