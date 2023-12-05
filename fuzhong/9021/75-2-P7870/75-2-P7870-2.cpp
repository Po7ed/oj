#include <iostream>
#include <vector>
#define a first
#define b second
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<int,int>> v;
	int op;
	long long s=0,k,l,r;
	pair<long long,long long> t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%lld %lld",&l,&r);
			/* for(int j=l;j<=r;j++)
			{
				s.push_back((s.empty()?0:s.back())+j);
			} */
			v.push_back({l,r});
		}
		if(op==2)
		{
			scanf("%lld",&k);
			s=0;
			while(k)
			{
				t=v.back();
				v.pop_back();
				if(t.b-t.a+1>k)
				{
					v.push_back({t.a,t.b-k});
					t.a=t.b-k+1;
					s+=((t.a+t.b)*k/2);
					k=0;
				}
				else
				{
					s+=((t.a+t.b)*(t.b-t.a+1)/2);
					k-=(t.b-t.a+1);
				}
			}
			printf("%lld\n",s);
			/* int b=s.back(),e;
			for(int j=0;j<k;j++)
			{
				s.pop_back();
			}
			e=s.back();
			printf("%d\n",b-e); */
		}
	}
	return 0;	
}