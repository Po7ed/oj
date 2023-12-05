#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N=214,M=41;
int dp[N][M],sum[N][N];
string s,t;
vector<string> dic;
int n,m;

int main()
{
	// freopen("P1026_3.in","r",stdin);
	// freopen("log","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s.insert(s.end(),t.begin(),t.end());
	}
	n*=20;
	int d;
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		cin>>t;
		dic.push_back(t);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			bitset<N> vis;
			string now=s.substr(i,j-i+1);
			// printf("<%s:%d>\n",now.c_str(),sum[i][j]);
			for(string wd:dic)
			{
				// printf("TRY:%s\n",wd.c_str());
				size_t pos=now.find(wd);
				while(pos!=s.npos)
				{
					if(!vis[pos])
					{
						sum[i][j]++;
						vis[pos]=true;
					}
					// printf(" %llu\n",pos);
					pos=now.find(wd,pos+1);
				}
			}
			// printf("</%s:%d>\n\n",now.c_str(),sum[i][j]);
		}
	}
	// for(int i=1;i<=m;i++)
	// {
	// 	dp[i][i]=dp[i-1][i-1]+sum[i][i];
	// }
	for(int i=0;i<n;i++)
	{
		dp[i][1]=sum[0][i];
		for(int j=2;j<=min(m,i+1);j++)// cut j parts
		{
			for(int k=0;k<i;k++)
			{
				if(dp[k][j-1])
				{
					dp[i][j]=max(dp[i][j],dp[k][j-1]+sum[k+1][i]);
				}
				// printf("%d %d %d+%d\n",i,j,dp[k][j-1],sum[k+1][i]);
			}
		}
	}
	printf("%d",dp[n-1][m]);
	return 0;
}