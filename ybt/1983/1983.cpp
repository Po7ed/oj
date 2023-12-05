#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<pair<int,int>> q;
	int n,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int type,t,v;
		scanf("%d %d %d",&type,&v,&t);
		if(type)
		{
			if(!q.empty())
			{
				while(!q.empty()&&q.front().first<t)q.erase(q.begin());
				if(q.empty())ans+=v;
				else if(q.front().second>=v)
				{
					q.erase(q.begin());
				}
				else
				{
					int k=1;
					while(q[k].second<v&&k<q.size())k++;
					if(k==q.size())ans+=v;
					else q.erase(q.begin()+k);
				}
			}
			else ans+=v;
		}
		else
		{
			pair<int,int> tmp;
			tmp.first=t+45;
			tmp.second=v;
			q.push_back(tmp);
			ans+=v;
		}
	}
	cout<<ans<<endl;
	return 0;
}