#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	deque<int> d;
	bool b[2*n];
	fill(b,b+2*n,false);
	for(int i=0;i<2*n;i++)
	{
		d.push_back(i);
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		j+=(m-1);
		j%=(2*n-i);
		b[d[j]]=true;
		d.erase(d.begin()+j);
	}
	for(int i=0;i<2*n;i++)
	{
		if(!(i%50)&&i)
			puts("");
		printf("%c",(b[i]?'B':'G'));
	}
	return 0;
}