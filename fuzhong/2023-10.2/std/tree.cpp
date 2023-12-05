// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
#include<queue>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
#define gi(x) read(x)
#define gii(x,y) read(x),read(y)
#define giii(x,y,z) read(x),read(y),read(z)
#define ms(f,x) memset(f,x,sizeof f)
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
namespace IO{
    #define gc getchar()
    #define pc(x) putchar(x)
    template<typename T>inline void read(T &x){
        x=0;int f=1;char ch=gc;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
        while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=gc;x*=f;return;
    }
    template<typename T>inline void write(T x=0){
        T wr[51];wr[0]=0;if(x<0)pc('-'),x=-x;if(!x)pc(48);
        while(x)wr[++wr[0]]=x%10,x/=10;while(wr[0])pc(48+wr[wr[0]--]);putchar('\n');return;
    }
}
using IO::read;
using IO::write;
const int N=4e6+11;
typedef long long ll;
const ll inf=(1ll<<60);
#define pii pair<ll,int>
#define mp make_pair
#define se second
#define fi first
int n,m,s,t,tot,x,y,z,k,p;
ll dis[N];
bool vis[N];
int las[N],to[N],nxt[N],w[N],dep[N];
void add(int x,int y,int z){
	nxt[++tot]=las[x];
	las[x]=tot;
	to[tot]=y;
	w[tot]=z;
}
priority_queue<pii>heap;
void dij(int s){
	rep(i,1,n*3)
		dis[i]=inf;
	dis[s]=0;
	heap.push(mp(0,s));
	while(!heap.empty()){
		int x=heap.top().se;
		heap.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(register int e=las[x];e;e=nxt[e])
			if(dis[to[e]]>dis[x]+w[e]){
				dis[to[e]]=dis[x]+w[e];
				heap.push(mp(-dis[to[e]],to[e]));
			}
	}
	rep(i,1,n)
		printf("%lld\n",dis[i]);
}
void dfs(int x,int fa){
	for(int e=las[x];e;e=nxt[e]){
		if(to[e]==fa)continue;
		dep[to[e]]=dep[x]+1;
		dfs(to[e],x);
	}
}
int main(){
	open(tree);
	gi(n);
	rep(i,1,n-1){
		giii(x,y,z);
		add(x,y,z);
		add(y,x,z);
	}
	dep[1]=1;
	dfs(1,1);
	gii(k,p);
	gi(s);
	rep(i,1,n){
        add(n+2*dep[i]-1,i,p);
        add(n+2*(dep[i]+1),i,p);
        if(dep[i]+k<=n)
			add(i,n+2*(dep[i]+k)-1,0);
		if(dep[i]-k>=1)
    		add(i,n+2*(dep[i]-k+1),0);
	}
	dij(s);
	return 0;
}