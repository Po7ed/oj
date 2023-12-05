#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%d",k-n%k);
	return 0;
}