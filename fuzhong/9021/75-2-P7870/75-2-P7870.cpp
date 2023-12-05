#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// freopen("stack2.in","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	// vector<int> s;
	int s[7000000],tot=1;
	s[0]=0;
	int op,l,r,k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %d",&l,&r);
			for(int j=l;j<=r;j++)
			{
				s[tot]=s[tot-1]+j;
				tot++;
				// s.push_back((s.empty()?0:s.back())+j);
			}
		}
		if(op==2)
		{
			scanf("%d",&k);
			int b=s[tot-1],e;
			/* for(int j=0;j<k;j++)
			{
				s.pop_back();
			} */
			tot-=k;
			// e=s.back();
			e=s[tot-1];
			printf("%d\n",b-e);
		}
	}
	return 0;	
}