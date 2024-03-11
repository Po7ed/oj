#include <iostream>
#include <string>
#include <cstring>

typedef long long ll;
template<const int B,const int M1,const int M2,const int N>
struct hash
{
	int k1,k2,len;
	int *lsh1,*rsh1,*lsh2,*rsh2;
	int qpow(int base,int pow,const int mod)
	{
		int res=1;
		while(pow)
			(pow&1)&&(res=1ll*res*base%mod),
			base=1ll*base*base%mod,
			pow>>=1;
		return res;
	}
	void initsh()
	{
		int tlsh1[N],trsh1[N],tlsh2[N],trsh2[N];
		tlsh1[0]=tlsh2[0]=trsh1[0]=trsh2[0]=1;
		for(int i=1;i<N;i++)
		{
			tlsh1[i]=1ll*tlsh1[i-1]*B%M1;
			tlsh2[i]=1ll*tlsh2[i-1]*B%M2;
		}
		int iB1=qpow(B,M1-2,M1),iB2=qpow(B,M2-2,M2);
		for(int i=1;i<N;i++)
		{
			trsh1[i]=1ll*trsh1[i-1]*iB1%M1;
			trsh2[i]=1ll*trsh2[i-1]*iB2%M2;
		}
		lsh1=tlsh1,rsh1=trsh1,lsh2=tlsh2,rsh2=trsh2;
	}
	hash(int *_lsh1=nullptr,int *_rsh1=nullptr,int *_lsh2=nullptr,int *_rsh2=nullptr,
	int _k1=0,int _k2=0,int _len=0):k1(_k1),k2(_k2),len(_len)
	{
		if(_lsh1==nullptr||_rsh1==nullptr||_lsh2==nullptr||_rsh2==nullptr)initsh();
		else lsh1=_lsh1,rsh1=_rsh1,lsh2=_lsh2,rsh2=_rsh2;
	}
	inline hash<B,M1,M2,N>& operator = (std::string &s)
	{
		len=s.length();
		k1=k2=0;
		for(char c:s)
		{
			k1=(1ll*k1*B+c)%M1;
			k2=(1ll*k2*B+c)%M2;
		}
		return *this;
	}
	inline hash<B,M1,M2,N>& operator = (char *s)
	{
		len=strlen(s);
		k1=k2=0;
		for(int i=0;i<len;i++)
		{
			k1=(1ll*k1*B+s[i])%M1;
			k2=(1ll*k2*B+s[i])%M2;
		}
	}
	inline bool operator == (hash<B,M1,M2,N> b){return k1==b.k1&&k2==b.k2&&len==b.len;}
	hash<B,M1,M2,N>& append(char c)
	{
		k1=(1ll*k1*B+c)%M1;
		k2=(1ll*k2*B+c)%M2;
		len++;
		return *this;
	}
	hash<B,M1,M2,N> substr(int l,int r)// [l,r)
	{
		if(l==r)return {};
		hash ret=*this;
		ret.k1=1ll*k1*rsh1[len-r]%M1%lsh1[len-l];
		ret.k2=1ll*k2*rsh2[len-r]%M2%lsh2[len-l];
		ret.len=r-l;
		return ret;
	}
};

constexpr int B=300,M1=1e9+7,M2=1e9+9,N=5114514;
int pre[N];

int main()
{
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
	std::string s;
	std::cin>>s;
	hash<B,M1,M2,N> h;
	h=s;
	int n=s.length();
	pre[0]=1;
	ll ans=pre[0];
	for(int i=1;i<n;i++)
	{
		if(h.substr(0,(i+1)>>1)==h.substr(i-((i+1)>>1),i))
		{
			pre[i]=pre[i>>1]+1;
		}
		ans+=pre[i];
	}
	std::cout<<ans<<'\n';
	return 0;
}