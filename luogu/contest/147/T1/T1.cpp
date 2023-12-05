#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int d=0,x=0,z=0;
	for(char c:s)
	{
		if('A'<=c&&c<='Z')
		{
			d++;
		}
		else if('a'<=c&&c<='z')
		{
			x++;
		}
		else if('0'<=c&&c<='9')
		{
			z++;
		}
	}
	printf("%d %d %d",z,x,d);
	return 0;
}