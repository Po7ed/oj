#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	string s;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		cin>>s;
		printf("%d\n",(n*n*n+3*n*n+2*n)/6);
	}
	return 0;
}