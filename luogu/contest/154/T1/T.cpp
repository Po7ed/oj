#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b+c+d<51)
	{
		puts("Rabbit wins");
	}
	else
	{
		puts("Rabbit lose");
	}
	return 0;
}