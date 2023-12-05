#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
    string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if((s.back()-'0')%2==0)
			puts("even");
		else
			puts("odd");
	}
    
}