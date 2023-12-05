#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> list={-2147483647,2147483647};
int main()
{
	int n;
	scanf("%d",&n);
	int opt,x;
	while(n--)
	{
		scanf("%d %d",&opt,&x);
		     if(opt==5)list.insert(lower_bound(list.begin(),list.end(),x),x);
		else if(opt==1)printf("%d\n",(lower_bound(list.begin(),list.end(),x)-list.begin()));
		else if(opt==2)printf("%d\n",list[x]);
		else if(opt==3)printf("%d\n",*(lower_bound(list.begin(),list.end(),x)-1));
		else if(opt==4)printf("%d\n",*upper_bound(list.begin(),list.end(),x));
	}
	return 0;
}