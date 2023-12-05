#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n,k;
	vector<int> v,vv;
	set<int> s;
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&k);
		if(k==1)
		{
			puts("yes");
			for(int j=1;j<=n;j++)
			{
				printf("%d ",j);
			}
			puts("");
		}
		else
		{
			v.clear();
			for(int j=1;j<=n;j++)
			{
				v.push_back(j);
			}
			vv=v;
			// v.push_back(1);
			while(1)
			{
				s.clear();
				for(int j=1;j<n;j++)
				{
					s.insert(__gcd(v[j-1],v[j]));
				}
				s.insert(__gcd(v[0],v[n-1]));
				if(s.size()==k)
				{
					puts("yes");
					for(int i=0;i<n;i++)
					{
						printf("%d ",v[i]);
					}
					puts("");
					break;
				}
				next_permutation(v.begin(),v.end());
				if(vv==v)
				{
					puts("no");
					break;
				}
			}
		}
	}
	return 0;
}