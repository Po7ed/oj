#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int S=1145,N=10;
int n,k;
ll dp[N][N*N][S];
vector<int> set;

#define pc(x) __builtin_popcount(x)

int main() 
{
    cin>>n>>k;
    for(int s=0;s<(1<<n);s++)
    {
        if(!(((s<<1)|(s>>1))&s))
		{
			set.push_back(s);
		}
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
		for(int s1:set)
        {
			for(int s2:set)
            {
                if(!((s2|(s2<<1)|(s2>>1))&s1))
                {
					for(int j=0;j<=k;j++)
					{
						if(j>=pc(s1))
						{
							dp[i][j][s1]+=dp[i-1][j-pc(s1)][s2];   
						}
					}
                }
            }
        }
    }
    ll ans=0;
	for(int s:set)
	{
		ans+=dp[n][k][s];
	}
    printf("%lld",ans);
    return 0;
}