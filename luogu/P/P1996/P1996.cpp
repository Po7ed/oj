#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	deque<int> d;
	for(int i=0;i<n;i++)
	{
		d.push_back(i);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		j+=(m-1);
		j%=(n-i);
		printf("%d ",d[j]+1);
		d.erase(d.begin()+j);
	}
	return 0;
}