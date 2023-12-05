#include <iostream>
using namespace std;
int main()
{
	int k=0;
	cin>>k;
	int gold=0,date=0,i=1;
	for(;date<k;i++)
	{
		gold+=i*i;
		date+=i;
	}
	printf("%d",gold-(date-k)*(i-1));
	return 0;
}