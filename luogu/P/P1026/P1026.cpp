#include <iostream>
#include <vector>
using namespace std;

const int N=214,M=41;
int mat[N][N],dp[N][M];
string s,t;
vector<string> dic;
int n,m,ans=-1;

void dfs(int dep=1,int pos=0,int mated=0)
{
	for(int i=1;i<dep;i++)
	{
		printf("-");
	}
	printf("%d\n",mated);
	if(pos>=n)
	{
		return;
	}
	if(dep==m)
	{
		ans=max(ans,mated);
		return;
	}
	for(int i=pos+1;i<n;i++)
	{
		dfs(dep+1,i+1,mated+mat[pos][i]);
	}
}

int main()
{
	freopen("log","w",stdout);
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
	size_t pos;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				for(string ecwd:dic)
				{
					if(k+ecwd.length()>j)continue;
					pos=s.substr(k).find_first_of(ecwd);
					cout<<s.substr(k)<<" "<<(int)pos<<"\n";
					// printf(":i%d j%d %s pos%d",i,j,ecwd.c_str(),pos);
					if(pos==0)
					{
						// printf(" T\n");
						mat[i][j]++;
						break;
					}
					// puts("");
				}
			}
			printf(":%d %d %d\n",i,j,mat[i][j]);
		}
	}

	// for(int i=0;i<n;i++)// 0--i
	// {
	// 	dp[i][1]=mat[0][i];
	// 	for(int j=2;j<=m;j++)// ////}j
	// 	{
	// 		for(int k=j-1;k<i;k++)// 0--k:j-1  k+1--i
	// 		{
	// 			dp[i][j]=max(dp[i][j],dp[k][j-1]+mat[k][i]);
	// 		}
	// 		printf("%d %d %d\n",i,j,dp[i][j]);
	// 	}
	// }
	// printf("%d",dp[n-1][m]);
	dfs();
	printf("%d",ans);
	return 0;
}